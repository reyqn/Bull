#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include <Bull/Core/FileSystem/Unix/FileImplUnix.hpp>

namespace Bull
{
    namespace prv
    {
        /*! \brief Create a file
         *
         * \param name The name of the file to create
         *
         * \return Return true if the file was created successfully, else otherwise
         *
         */
        bool FileImplUnix::create(const String& name)
        {
            int handler = ::open(name, O_CREAT | O_TRUNC | O_EXCL, S_IRWXU);

            if(handler == -1)
            {
                return false;
            }

            close(handler);

            return true;
        }

        /*! \brief Check if a file exists
         *
         * \param name The name of the file to check
         *
         * \return Return true if the file exists, false otherwise
         *
         */
        bool FileImplUnix::exists(const String& name)
        {
            return access(name, F_OK) != -1;
        }

        /*! \brief Copy a file
         *
         * \param path The path (relative or absolute) of the file to copy
         * \param path The new path (relative or absolute) of the file
         *
         * \return Return true if the copy was successfully, false otherwise
         *
         */
        bool FileImplUnix::copy(const String& path, const String& newPath)
        {

        }

        /*! \brief Delete a file
         *
         * \param name The name of the file to delete
         *
         * \return Return true if the file was deleted successfully, false otherwise
         *
         */
        bool FileImplUnix::remove(const String& name)
        {
            return unlink(name) != -1;
        }

        /*! \brief Destructor
         *
         */
        FileImplUnix::~FileImplUnix()
        {
            /// Nothing
        }

        /*! \brief Open a file
         *
         * \param name The name of the file
         * \param mode The opening mode of the file (read, write or both)
         *
         * \return Return true if the file was open successfully, false otherwise
         *
         */
        bool FileImplUnix::open(const String& name, Uint32 mode)
        {
            return false;
        }

        /*! \brief Read in a file
         *
         * \param dst The destination of the read data
         * \param size The number of byte to read
         *
         * \param Return the number of byte read
         *
         */
        Uint64 FileImplUnix::read(void* dst, Uint64 size)
        {
            return 0;
        }

        /*! \brief Write a byte in this file
         *
         * \param byte A byte to write
         *
         */
        Uint64 FileImplUnix::write(const void* data, Uint64 size)
        {
            return 0;
        }

        /*! \brief Get the date of the creation of the file
         *
         * \return Return the date of the creation of the file
         *
         */
        Date FileImplUnix::getCreationDate() const
        {
            return Date();
        }

        /*! \brief Get the date of the creation of the file
         *
         * \return Return the date of the last access of the file
         *
         */
        Date FileImplUnix::getLastAccessDate() const
        {
            return Date();
        }

        /*! \brief Get the date of the creation of the file
         *
         * \return Return the date of the last write of the file
         *
         */
        Date FileImplUnix::getLastWriteDate() const
        {
            return Date();
        }

        /*! \brief Get the position of the cursor in the file
         *
         * \return Return the position of the cursor in the file
         *
         */
        Uint64 FileImplUnix::getCursor() const
        {
            return 0;
        }

        /*! \brief Move the reading position in the file
         *
         * \param offset The offset to move the cursor
         *
         * \return Return true if the cursor reached its new position, false otherwise
         *
         */
        Uint64 FileImplUnix::moveCursor(Int64 offset)
        {
            return 0;
        }

        /*! \brief Set the reading position in the file
         *
         * \param position The position to seek to
         *
         * \return Return true if the cursor reached its new position, false otherwise
         *
         */
        Uint64 FileImplUnix::setCursor(Uint64 offset)
        {
            return 0;
        }

        /*! \brief Get the size of the file
         *
         * \return Return the size of the file
         *
         */
        Uint64 FileImplUnix::getSize() const
        {
            return 0;
        }

        /*! \brief Get the file system handler
         *
         * \return Return the native file system handler
         *
         */
        FileHandler FileImplUnix::getSystemHandler() const
        {
            return 0;
        }
    }
}