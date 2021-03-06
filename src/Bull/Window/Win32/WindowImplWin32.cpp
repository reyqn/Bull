#include <Bull/Window/Win32/WindowImplWin32.hpp>

/// GCC missing define
#ifndef WM_XBUTTONDOWN
    #define WM_XBUTTONDOWN 0x020B
#endif
#ifndef WM_XBUTTONUP
    #define WM_XBUTTONUP 0x020C
#endif
#ifndef XBUTTON1
    #define XBUTTON1 0x0001
#endif
#ifndef XBUTTON2
    #define XBUTTON2 0x0002
#endif
#ifndef VK_OEM_PLUS
    #define VK_OEM_PLUS 0xBB
#endif
#ifndef VK_OEM_COMMA
    #define VK_OEM_COMMA 0xBC
#endif
#ifndef VK_OEM_PERIOD
    #define VK_OEM_PERIOD 0xBE
#endif
#ifndef VK_OEM_102
    #define VK_OEM_102 0xE2
#endif
#ifndef GWL_USERDATA
    #define GWL_USERDATA -21
#endif

namespace Bull
{
    namespace prv
    {
        namespace
        {
            HINSTANCE instance           = GetModuleHandle(nullptr);
            LPCWSTR   windowClassName    = L"BullWindow";
            unsigned int instanceCounter = 0;
        }

        /*! \brief Register the window class
         *
         * \return Return true if the class was registered successfully, false otherwise
         *
         */
        bool WindowImplWin32::registerWindowClass()
        {
            WNDCLASSEXW winClass;

            winClass.cbSize        = sizeof(WNDCLASSEXW);
            winClass.style         = 0;
            winClass.lpfnWndProc   = WindowImplWin32::globalEvent;
            winClass.cbClsExtra    = 0;
            winClass.cbWndExtra    = 0;
            winClass.hInstance     = instance;
            winClass.hIcon         = LoadIcon(instance, IDI_APPLICATION);
            winClass.hCursor       = LoadCursor(nullptr, IDC_ARROW);
            winClass.hbrBackground = nullptr;
            winClass.lpszMenuName  = nullptr;
            winClass.lpszClassName = windowClassName;
            winClass.hIconSm       = nullptr;

            return RegisterClassExW(&winClass);
        }

        /*! \brief Window callback event
         *
         * \param handler The window concerned by the event
         * \param message The windows message
         * \param wParam The WPARAM
         * \param lParam The LPARAM
         *
         * \return Return 0 if the message was WM_CLOSE, a value to continue otherwise
         *
         */
        LRESULT CALLBACK WindowImplWin32::globalEvent(HWND handler, UINT message, WPARAM wParam, LPARAM lParam)
        {
            WindowImplWin32* windowImpl = reinterpret_cast<WindowImplWin32*>(GetWindowLong(handler, GWL_USERDATA));

            if(windowImpl)
            {
                windowImpl->processEvent(message, wParam, lParam);
            }

            if(message == WM_CLOSE)
            {
                return 0;
            }

            return DefWindowProc(handler, message, wParam, lParam);
        }

        /*! \brief Convert a windows key value to a Bull::Keyboard::Key
         *
         * \param vkey To VK to convert
         *
         * \return Return the Bull::Keyboard::Key equivalent
         *
         */
        Keyboard::Key WindowImplWin32::convertVKToBullkey(WPARAM vkey)
        {
            switch(vkey)
            {
                case 'A':           return Keyboard::Key::A;
                case 'B':           return Keyboard::Key::B;
                case 'C':           return Keyboard::Key::C;
                case 'D':           return Keyboard::Key::D;
                case 'E':           return Keyboard::Key::E;
                case 'F':           return Keyboard::Key::F;
                case 'G':           return Keyboard::Key::G;
                case 'H':           return Keyboard::Key::H;
                case 'I':           return Keyboard::Key::I;
                case 'J':           return Keyboard::Key::J;
                case 'K':           return Keyboard::Key::K;
                case 'L':           return Keyboard::Key::L;
                case 'M':           return Keyboard::Key::M;
                case 'N':           return Keyboard::Key::N;
                case 'O':           return Keyboard::Key::O;
                case 'P':           return Keyboard::Key::P;
                case 'Q':           return Keyboard::Key::Q;
                case 'R':           return Keyboard::Key::R;
                case 'S':           return Keyboard::Key::S;
                case 'T':           return Keyboard::Key::T;
                case 'U':           return Keyboard::Key::U;
                case 'V':           return Keyboard::Key::V;
                case 'W':           return Keyboard::Key::W;
                case 'X':           return Keyboard::Key::X;
                case 'Y':           return Keyboard::Key::Y;
                case 'Z':           return Keyboard::Key::Z;
                case '0':           return Keyboard::Key::Num0;
                case '1':           return Keyboard::Key::Num1;
                case '2':           return Keyboard::Key::Num2;
                case '3':           return Keyboard::Key::Num3;
                case '4':           return Keyboard::Key::Num4;
                case '5':           return Keyboard::Key::Num5;
                case '6':           return Keyboard::Key::Num6;
                case '7':           return Keyboard::Key::Num7;
                case '8':           return Keyboard::Key::Num8;
                case '9':           return Keyboard::Key::Num9;
                case VK_NUMLOCK:    return Keyboard::Key::NumLock;
                case VK_NUMPAD0:    return Keyboard::Key::NumPad0;
                case VK_NUMPAD1:    return Keyboard::Key::NumPad1;
                case VK_NUMPAD2:    return Keyboard::Key::NumPad2;
                case VK_NUMPAD3:    return Keyboard::Key::NumPad3;
                case VK_NUMPAD4:    return Keyboard::Key::NumPad4;
                case VK_NUMPAD5:    return Keyboard::Key::NumPad5;
                case VK_NUMPAD6:    return Keyboard::Key::NumPad6;
                case VK_NUMPAD7:    return Keyboard::Key::NumPad7;
                case VK_NUMPAD8:    return Keyboard::Key::NumPad8;
                case VK_NUMPAD9:    return Keyboard::Key::NumPad9;
                case VK_DECIMAL:    return Keyboard::Key::NumPadDot;
                case VK_ADD:        return Keyboard::Key::Add;
                case VK_SUBTRACT:   return Keyboard::Key::Substract;
                case VK_MULTIPLY:   return Keyboard::Key::Multiply;
                case VK_DIVIDE:     return Keyboard::Key::Divide;
                case VK_F1:         return Keyboard::Key::F1;
                case VK_F2:         return Keyboard::Key::F2;
                case VK_F3:         return Keyboard::Key::F3;
                case VK_F4:         return Keyboard::Key::F4;
                case VK_F5:         return Keyboard::Key::F5;
                case VK_F6:         return Keyboard::Key::F6;
                case VK_F7:         return Keyboard::Key::F7;
                case VK_F8:         return Keyboard::Key::F8;
                case VK_F9:         return Keyboard::Key::F9;
                case VK_F10:        return Keyboard::Key::F10;
                case VK_F11:        return Keyboard::Key::F11;
                case VK_F12:        return Keyboard::Key::F12;
                case VK_F13:        return Keyboard::Key::F13;
                case VK_F14:        return Keyboard::Key::F14;
                case VK_F15:        return Keyboard::Key::F15;
                case VK_F16:        return Keyboard::Key::F16;
                case VK_F17:        return Keyboard::Key::F17;
                case VK_F18:        return Keyboard::Key::F18;
                case VK_F19:        return Keyboard::Key::F19;
                case VK_F20:        return Keyboard::Key::F20;
                case VK_F21:        return Keyboard::Key::F21;
                case VK_F22:        return Keyboard::Key::F22;
                case VK_F23:        return Keyboard::Key::F23;
                case VK_F24:        return Keyboard::Key::F24;
                case VK_LEFT:       return Keyboard::Key::Left;
                case VK_RIGHT:      return Keyboard::Key::Right;
                case VK_UP:         return Keyboard::Key::Up;
                case VK_DOWN:       return Keyboard::Key::Down;
                case VK_SPACE:      return Keyboard::Key::Space;
                case VK_ESCAPE:     return Keyboard::Key::Escape;
                case VK_CONTROL:    return Keyboard::isKeyPressed(Keyboard::LeftControl) ? Keyboard::LeftControl : Keyboard::RightControl;
                case VK_LCONTROL:   return Keyboard::Key::LeftControl;
                case VK_RCONTROL:   return Keyboard::Key::RightControl;
                case VK_MENU:       return Keyboard::isKeyPressed(Keyboard::LeftAlt) ? Keyboard::LeftAlt : Keyboard::RightAlt;
                case VK_LMENU:      return Keyboard::Key::LeftAlt;
                case VK_RMENU:      return Keyboard::Key::RightAlt;
                case VK_LWIN:       return Keyboard::Key::LeftSystem;
                case VK_RWIN:       return Keyboard::Key::RightSystem;
                case VK_SHIFT:      return Keyboard::isKeyPressed(Keyboard::LeftShift) ? Keyboard::LeftShift : Keyboard::RightShift;
                case VK_LSHIFT:     return Keyboard::Key::LeftShift;
                case VK_RSHIFT:     return Keyboard::Key::RightShift;
                case VK_OEM_1:      return Keyboard::Key::OEM1;
                case VK_OEM_PERIOD: return Keyboard::Key::OEMPeriod;
                case VK_OEM_2:      return Keyboard::Key::OEM2;
                case VK_OEM_3:      return Keyboard::Key::OEM3;
                case VK_OEM_4:      return Keyboard::Key::OEM4;
                case VK_OEM_5:      return Keyboard::Key::OEM5;
                case VK_OEM_6:      return Keyboard::Key::OEM6;
                case VK_OEM_7:      return Keyboard::Key::OEM7;
                case VK_OEM_8:      return Keyboard::Key::OEM8;
                case VK_OEM_102:    return Keyboard::Key::OEM9;
                case VK_OEM_PLUS:   return Keyboard::Key::OEMPlus;
                case VK_OEM_COMMA:  return Keyboard::Key::OEMComma;
                case VK_TAB:        return Keyboard::Key::Tab;
                case VK_BACK:       return Keyboard::Key::Back;
                case VK_RETURN:     return Keyboard::Key::Enter;
                case VK_CAPITAL:    return Keyboard::Key::CapsLock;
                case VK_APPS:       return Keyboard::Key::Apps;
                case VK_DELETE:     return Keyboard::Key::Delete;
                case VK_INSERT:     return Keyboard::Key::Insert;
                case VK_PRIOR:      return Keyboard::Key::PageUp;
                case VK_NEXT:       return Keyboard::Key::PageDown;
                case VK_END:        return Keyboard::Key::End;
                case VK_HOME:       return Keyboard::Key::Home;
                case VK_PAUSE:      return Keyboard::Key::Pause;
                case VK_SNAPSHOT:   return Keyboard::Key::ScreenShot;
                case VK_SCROLL:     return Keyboard::Key::Scroll;
            }
        }

        /*! \brief Convert a Bull::Window::Style to a WS
         *
         * \param style The Bull::Window::Style to convert
         *
         * \return Return the WS equivalent
         *
         */
        DWORD WindowImplWin32::computeStyle(Uint32 style)
        {
            DWORD windowStyle = 0;

            if(style & (Window::Style::Visible) || style & (Window::Style::Fullscreen))
            {
                windowStyle |= WS_VISIBLE;
            }

            if(style & (Window::Style::Closable))
            {
                windowStyle |= WS_SYSMENU;
            }

            if(style & (Window::Style::Maximizable))
            {
                windowStyle |= WS_MAXIMIZEBOX;
            }

            if(style & (Window::Style::Minimizable))
            {
                windowStyle |= WS_MINIMIZEBOX;
            }

            if(style & (Window::Style::Resizable))
            {
                windowStyle |= WS_THICKFRAME;
            }

            return windowStyle;
        }

        /*! \brief Constructor
         *
         * \param mode The VideoMode to use
         * \param title The title to use in the window
         * \param style The window decoration
         *
         */
        WindowImplWin32::WindowImplWin32(const VideoMode& mode, const String& title, Uint32 style) :
            m_isResizing(false)
        {
            DWORD winStyle = computeStyle(style);
            unsigned int width, height;

            if(instanceCounter == 0)
            {
                registerWindowClass();
            }

            if(!(style & Window::Style::Fullscreen))
            {
                RECT rectangle = {0, 0, mode.width, mode.height};
                AdjustWindowRect(&rectangle, winStyle, false);
                width  = rectangle.right - rectangle.left;
                height = rectangle.bottom - rectangle.top;
            }
            else
            {
                width  = mode.width;
                height = mode.height;
            }

            m_handler = CreateWindowExW(0,
                                        windowClassName,
                                        reinterpret_cast<LPCWSTR>(static_cast<const char*>(title)),
                                        winStyle,
                                        CW_USEDEFAULT, CW_USEDEFAULT,
                                        width, height,
                                        0,
                                        0,
                                        instance,
                                        nullptr);

            SetWindowLong(m_handler, GWL_USERDATA, (LONG_PTR)this);

            UpdateWindow(m_handler);

            m_lastSize     = getSize();
            m_lastPosition = getPosition();

            instanceCounter += 1;
        }

        /*! \brief Destructor
         *
         */
        WindowImplWin32::~WindowImplWin32()
        {
            instanceCounter -= 1;

            if(instanceCounter == 0)
            {
                UnregisterClassW(windowClassName, instance);
            }

            DestroyWindow(m_handler);
        }

        /*! \brief Process events stacked so far
         *
         */
        void WindowImplWin32::startProcessEvents()
        {
            MSG message;

            while(PeekMessage(&message, m_handler, 0, 0, PM_REMOVE))
            {
                TranslateMessage(&message);
                DispatchMessage(&message);
            }
        }

        /*! \brief Minimize a window
         *
         */
        void WindowImplWin32::minimize()
        {
            ShowWindow(m_handler, SW_SHOWMINIMIZED);
        }

        /*! \brief Check if the window is minimized
         *
         * \return Return true if the window is minimized, false otherwise
         *
         */
        bool WindowImplWin32::isMinimized() const
        {
            return IsIconic(m_handler);
        }

        /*! \brief Maximize a window
         *
         */
        void WindowImplWin32::maximize()
        {
            ShowWindow(m_handler, SW_SHOWMAXIMIZED);
        }

        /*! \brief Check if the window is maximized
         *
         * \return Return true if the window is minimized, false otherwise
         *
         */
        bool WindowImplWin32::isMaximized() const
        {
            WINDOWPLACEMENT placement;
            placement.length = sizeof(WINDOWPLACEMENT);

            GetWindowPlacement(m_handler, &placement);

            return placement.showCmd == SW_MAXIMIZE;
        }

        /*! \brief Enable or disable the capture of the cursor inside the window
         *
         * \param enable The state of the capture
         *
         */
        void WindowImplWin32::enableCaptureCursor(bool capture)
        {
            if(capture)
            {
                RECT winRect;

                GetClientRect(m_handler, &winRect);

                ClipCursor(&winRect);
            }
            else
            {
                ClipCursor(nullptr);
            }
        }

        /*! \brief Hide or show the cursor
         *
         * \param enable The state of the cursor
         *
         */
        void WindowImplWin32::showCursor(bool enable)
        {
            ShowCursor(enable);
        }

        /*! \brief Set the size of the window
         *
         * \param size The new size of the window
         *
         */
        void WindowImplWin32::setPosition(const Vector2I& position)
        {
            SetWindowPos(m_handler, 0, position.x, position.y, 0, 0, SWP_NOSIZE);
        }

        /*! \brief Get the position in the screen of the window
         *
         * \return Return the window position
         *
         */
        Vector2I WindowImplWin32::getPosition() const
        {
            RECT r;

            GetWindowRect(m_handler, &r);

            return Vector2I(r.left, r.top);
        }

        /*! \brief Set the size of the window
         *
         * \param size The new size of the window
         *
         */
        void WindowImplWin32::setSize(const Vector2UI& size)
        {
            SetWindowPos(m_handler, 0, 0, 0, size.x, size.y, SWP_NOMOVE);
        }

        /*! \brief Get the size of the window
         *
         * \return Return the size of the window
         *
         */
        Vector2UI WindowImplWin32::getSize() const
        {
            RECT r;

            GetClientRect(m_handler, &r);

            return Vector2UI(r.right - r.left, r.bottom - r.top);
        }

        /*! \brief Set the title of the window
         *
         * \param title The title to set to the window
         *
         */
        void WindowImplWin32::setTitle(const String& title)
        {
            SetWindowTextW(m_handler, reinterpret_cast<LPCWSTR>(static_cast<const char*>(title)));
        }

        /*! \brief Get the title of the window
         *
         * \return Return the title of the window
         *
         */
        String WindowImplWin32::getTitle() const
        {
            wchar_t* titleBuffer = new wchar_t[1024];
            String title;

            GetWindowTextW(m_handler, titleBuffer, 1024);

            title = reinterpret_cast<char*>(titleBuffer);

            delete[] titleBuffer;

            return title;
        }

        /*! \brief Check if the window has the focus
         *
         * \param Return true if the window has the focus, false otherwise
         *
         */
        bool WindowImplWin32::hasFocus() const
        {
            return GetFocus() == m_handler;
        }

        /*! \brief Enter or leave the fullscreen mode
         *
         * \param mode The VideoMode to use
         * \param fullscreen False to leave the fullscreen mode, true to enter the fullscreen mode
         *
         * \return Return true if the switch was done successfully, false otherwise
         *
         */
        bool WindowImplWin32::switchFullscreen(const VideoMode& mode, bool fullscreen)
        {
            bool isChangeSuccessful;

            if(fullscreen)
            {
                DEVMODE fullscreenSettings;

                EnumDisplaySettings(0, 0, &fullscreenSettings);
                fullscreenSettings.dmPelsWidth  = mode.width;
                fullscreenSettings.dmPelsHeight = mode.height;
                fullscreenSettings.dmBitsPerPel = mode.bitsPerPixel;
                fullscreenSettings.dmFields     = DM_PELSWIDTH | DM_PELSHEIGHT | DM_BITSPERPEL;

                SetWindowLongPtr(m_handler, GWL_EXSTYLE, WS_EX_APPWINDOW | WS_EX_TOPMOST);
                SetWindowLongPtr(m_handler, GWL_STYLE,   WS_POPUP        | WS_VISIBLE);

                SetWindowPos(m_handler, HWND_TOPMOST, 0, 0, mode.width, mode.height, SWP_SHOWWINDOW);

                isChangeSuccessful = ChangeDisplaySettings(&fullscreenSettings, CDS_FULLSCREEN) == DISP_CHANGE_SUCCESSFUL;

                ShowWindow(m_handler, SW_MAXIMIZE);
            }
            else
            {
                SetWindowLongPtr(m_handler, GWL_EXSTYLE, WS_EX_LEFT);
                SetWindowLongPtr(m_handler, GWL_STYLE,   WS_OVERLAPPEDWINDOW | WS_VISIBLE);

                isChangeSuccessful = ChangeDisplaySettings(0, CDS_RESET) == DISP_CHANGE_SUCCESSFUL;

                SetWindowPos(m_handler, HWND_NOTOPMOST, CW_USEDEFAULT, CW_USEDEFAULT, mode.width, mode.height, SWP_SHOWWINDOW);

                ShowWindow(m_handler, SW_RESTORE);
            }

            return isChangeSuccessful;
        }

        /*! \brief Show or hide the window
         *
         * \param visible True to show the window, false to hide the window
         *
         */
        void WindowImplWin32::setVisible(bool visible)
        {
            ShowWindow(m_handler, (visible) ? SW_SHOW : SW_HIDE);
        }

        /*! \brief Get the window system handler
         *
         * \return Return the native window system handler
         *
         */
        WindowHandler WindowImplWin32::getSystemHandler() const
        {
            return m_handler;
        }

        /*! \brief Process a single event
         *
         * \param message The windows message
         * \param wParam The WPARAM
         * \param lParam The LPARAM
         *
         */
        void WindowImplWin32::processEvent(UINT message, WPARAM wParam, LPARAM lParam)
        {
            switch(message)
            {
                case WM_CLOSE:
                {
                    Window::Event e;

                    e.type = Window::Event::Closed;

                    pushEvent(e);
                }
                break;

                case WM_SIZE:
                {
                    if(!m_isResizing && m_lastSize != getSize())
                    {
                        Window::Event e;

                        e.type                = Window::Event::Resized;
                        e.windowResize.width  = LOWORD(lParam);
                        e.windowResize.height = HIWORD(lParam);

                        m_lastSize = getSize();

                        pushEvent(e);
                    }
                }
                break;

                case WM_KILLFOCUS:
                {
                    Window::Event e;

                    e.type = Window::Event::LostFocus;

                    pushEvent(e);
                }
                break;

                case WM_SETFOCUS:
                {
                    Window::Event e;

                    e.type = Window::Event::GainFocus;

                    pushEvent(e);
                }
                break;

                case WM_ENTERSIZEMOVE:
                {
                    m_isResizing = true;
                }
                break;

                case WM_EXITSIZEMOVE:
                {
                    m_isResizing = false;

                    if(getSize() != m_lastSize)
                    {
                        Window::Event e;
                        m_lastSize = getSize();

                        e.type                = Window::Event::Resized;
                        e.windowResize.width  = m_lastSize.x;
                        e.windowResize.height = m_lastSize.y;

                        pushEvent(e);
                    }
                    if(getPosition() != m_lastPosition)
                    {
                        Window::Event e;
                        m_lastPosition = getPosition();

                        e.type         = Window::Event::Moved;
                        e.windowMove.x = getPosition().x;
                        e.windowMove.y = getPosition().y;

                        pushEvent(e);
                    }
                }
                break;

                case WM_KEYDOWN:
                case WM_SYSKEYDOWN:
                {
                    if(isKeyRepeatEnable() || ((HIWORD(lParam) & KF_REPEAT) == 0))
                    {
                        Window::Event e;

                        e.type        = Window::Event::KeyDown;
                        e.key.code    = convertVKToBullkey(wParam);
                        e.key.alt     = Keyboard::isKeyPressed(Keyboard::Key::Alt);
                        e.key.control = Keyboard::isKeyPressed(Keyboard::Key::Control);
                        e.key.shift   = Keyboard::isKeyPressed(Keyboard::Key::Shift);
                        e.key.system  = Keyboard::isKeyPressed(Keyboard::Key::System);

                        pushEvent(e);
                    }
                }
                break;

                case WM_KEYUP:
                case WM_SYSKEYUP:
                {
                    Window::Event e;

                    e.type        = Window::Event::KeyUp;
                    e.key.code    = convertVKToBullkey(wParam);
                    e.key.alt     = Keyboard::isKeyPressed(Keyboard::Key::Alt);
                    e.key.control = Keyboard::isKeyPressed(Keyboard::Key::Control);
                    e.key.shift   = Keyboard::isKeyPressed(Keyboard::Key::Shift);
                    e.key.system  = Keyboard::isKeyPressed(Keyboard::Key::System);

                    pushEvent(e);
                }
                break;

                case WM_MOUSEMOVE:
                {
                    Window::Event e;

                    e.type        = Window::Event::MouseMoved;
                    e.mouseMove.x = LOWORD(lParam);
                    e.mouseMove.y = HIWORD(lParam);

                    pushEvent(e);
                }
                break;

                case WM_LBUTTONDOWN:
                {
                    Window::Event e;

                    e.type               = Window::Event::MouseButtonDown;
                    e.mouseButton.button = Mouse::Button::Left;
                    e.mouseButton.x      = LOWORD(lParam);
                    e.mouseButton.y      = HIWORD(lParam);

                    pushEvent(e);
                }
                break;

                case WM_LBUTTONUP:
                {
                    Window::Event e;

                    e.type               = Window::Event::MouseButtonUp;
                    e.mouseButton.button = Mouse::Button::Left;
                    e.mouseButton.x      = LOWORD(lParam);
                    e.mouseButton.y      = HIWORD(lParam);

                    pushEvent(e);
                }
                break;

                case WM_MBUTTONDOWN:
                {
                    Window::Event e;

                    e.type               = Window::Event::MouseButtonDown;
                    e.mouseButton.button = Mouse::Button::Middle;
                    e.mouseButton.x      = LOWORD(lParam);
                    e.mouseButton.y      = HIWORD(lParam);

                    pushEvent(e);
                }
                break;

                case WM_MBUTTONUP:
                {
                    Window::Event e;

                    e.type               = Window::Event::MouseButtonUp;
                    e.mouseButton.button = Mouse::Button::Middle;
                    e.mouseButton.x      = LOWORD(lParam);
                    e.mouseButton.y      = HIWORD(lParam);

                    pushEvent(e);
                }
                break;

                case WM_RBUTTONDOWN:
                {
                    Window::Event e;

                    e.type               = Window::Event::MouseButtonDown;
                    e.mouseButton.button = Mouse::Button::Right;
                    e.mouseButton.x      = LOWORD(lParam);
                    e.mouseButton.y      = HIWORD(lParam);

                    pushEvent(e);
                }
                break;

                case WM_RBUTTONUP:
                {
                    Window::Event e;

                    e.type               = Window::Event::MouseButtonUp;
                    e.mouseButton.button = Mouse::Button::Right;
                    e.mouseButton.x      = LOWORD(lParam);
                    e.mouseButton.y      = HIWORD(lParam);

                    pushEvent(e);
                }
                break;

                case WM_XBUTTONDOWN:
                {
                    Window::Event e;

                    e.type               = Window::Event::MouseButtonDown;
                    e.mouseButton.button = (HIWORD(wParam) == XBUTTON1) ? Mouse::Button::Extra1 : Mouse::Button::Extra2;
                    e.mouseButton.x      = LOWORD(lParam);
                    e.mouseButton.y      = HIWORD(lParam);

                    pushEvent(e);
                }
                break;

                case WM_XBUTTONUP:
                {
                    Window::Event e;

                    e.type               = Window::Event::MouseButtonUp;
                    e.mouseButton.button = (HIWORD(wParam) == XBUTTON1) ? Mouse::Button::Extra1 : Mouse::Button::Extra2;
                    e.mouseButton.x      = LOWORD(lParam);
                    e.mouseButton.y      = HIWORD(lParam);

                    pushEvent(e);
                }
                break;

                case WM_MOUSEWHEEL:
                {
                    Window::Event e;

                    e.type              = Window::Event::MouseWheel;
                    e.mouseWheel.wheel  = Mouse::Wheel::Vertical;
                    e.mouseWheel.up     = (HIWORD(wParam) == 120);
                    e.mouseWheel.x      = LOWORD(lParam);
                    e.mouseWheel.y      = HIWORD(lParam);

                    pushEvent(e);
                }
                break;
            }
        }
    }
}
