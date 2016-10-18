#ifndef Bull_GlContext_hpp
#define Bull_GlContext_hpp

#include <Bull/Core/Pattern/NonCopyable.hpp>

#include <Bull/Window/WindowHandler.hpp>

namespace Bull
{
    namespace prv
    {
        class GlContext : public NonCopyable
        {
        public:

            /*! \brief Perform internal initialization
             *
             */
            static void globalInit();

            /*! \brief Perform internal cleanup
             *
             */
            static void globalCleanup();

            /*! \brief Ensure there is an active OpenGL context in this thead
             *
             */
            static void ensureContext();

            /*! \brief Create an OS specific instance of GlContext
             *
             * \return Return the created context
             *
             */
            static GlContext* createInstance();

            /*! \brief Create an OS specific instance of GlContext
             *
             * \param window The window to bind the created context
             * \param bitsPerPixel The number of bits to use per pixel
             *
             * \return Return the created context
             *
             */
            static GlContext* createInstance(WindowHandler window, unsigned int bitsPerPixel);

        public:

            /*! \brief Destructor
             *
             */
            virtual ~GlContext();

            /*! \brief Activate or deactivate the context
             *
             * \param active True to activate, false to deactivate the context
             *
             * \return Return true if the context's status changed successfully, false otherwise
             *
             */
            bool setActive(bool active);

            /*! \brief Display what has been rendered so far
             *
             */
            virtual void display() = 0;

        protected:

            GlContext() = default;

            /*! \brief Make the context current
             *
             * \return Return true if the context is now active, false otherwise
             *
             */
            virtual bool makeCurrent() = 0;

        private:

            /*! \brief Enable and perform initializations
             *
             */
            void initialize();
        };
    }
}

#endif // Bull_GlContext_hpp