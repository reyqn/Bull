#ifndef Bull_Vector4_hpp
#define Bull_Vector4_hpp

#include <cmath>

#include <Bull/Core/System/Export.hpp>

#include <Bull/Math/Vector/Vector3.hpp>

namespace Bull
{
    template<typename TComponent>
    struct BULL_API Vector4
    {
        /*! \brief Calculate the dot(scalar) product of two Vector4
         *
         * \param left  The left Vector4 of the product
         * \param right The right Vector4 of the product
         *
         * \return The value of the dot product of left and right
         *
         */
        static TComponent dotProduct(const Vector4& left, const Vector4& right);

        /*! \brief Default constructor
         *
         */
        Vector4();

        /*! \brief Constructor
         *
         * \param value The value of all components
         *
         */
        Vector4(TComponent value);

        /*! \brief Constructor
         *
         * \param x The x component
         * \param y The y component
         * \param z The z component
         * \param w The w component
         *
         */
        Vector4(TComponent x, TComponent y, TComponent z, TComponent w);

        /*! \brief Constructor
         *
         * \param copy The vector to copy
         * \param w The w component
         *
         */
        Vector4(const Vector3<TComponent>& copy, TComponent w = 0);

        /*! \brief Compute the length
         *
         * \return Return the length of the vector
         *
         */
        float getLength() const;

        /*! \brief Calculate the dot(scalar) product of two vectors
         *
         * \param right The other to calculate the dot product with
         *
         * \return The value of the dot product
         *
         */
        TComponent dotProduct(const Vector4& right);

        /*! \brief Compare two Vector4
         *
         * \param right The vector to compare
         *
         * \return Return true if this and right are equal, else return false
         *
         */
        bool operator==(const Vector4& right) const;

        /*! \brief Compare two Vector4
         *
         * \param right The vector to compare
         *
         * \return Return true if this and right are not equal, else return false
         *
         */
        bool operator!=(const Vector4& right) const;

        /*! \brief Add a vector to this one
         *
         * \param right The vector to add
         *
         * \return Return this after addition
         *
         */
        Vector4& operator+=(const Vector4& right);

        /*! \brief Negation operator
         *
         * \return Return the opposite of this Vector4
         *
         */
        Vector4 operator-() const;

        /*! \brief Subtract a vector to this one
         *
         * \param right The vector to subtract
         *
         * \return Return this after subtraction
         *
         */
        Vector4& operator-=(const Vector4& right);

        TComponent x, y, z, w;
    };

    /*! \brief Addition two Vector4
     *
     * \param left  The vector to add to right
     * \param right The vector to add to left
     *
     * \return Return a vector resulting of an addition of this and right
     *
     */
    template<typename TComponent>
    Vector4<TComponent> operator+(const Vector4<TComponent>& left, const Vector4<TComponent>& right);

    /*! \brief Addition two Vector4
     *
     * \param left  The number to add to right
     * \param right The vector to add to left
     *
     * \return Return a vector resulting of an addition of this and right
     *
     */
    template<typename TComponent>
    Vector4<TComponent> operator+(float left, const Vector4<TComponent>& right);

    /*! \brief Addition two Vector4
     *
     * \param left  The vector to add to right
     * \param right The number to add to left
     *
     * \return Return a vector resulting of an addition of this and right
     *
     */
    template<typename TComponent>
    Vector4<TComponent> operator+(const Vector4<TComponent>& left, float right);

    /*! \brief Subtract two Vector4
     *
     * \param left  The vector to subtract to right
     * \param right The vector to subtract to left
     *
     * \return Return a vector resulting of a subtraction of this and right
     *
     */
    template<typename TComponent>
    Vector4<TComponent> operator-(const Vector4<TComponent>& left, const Vector4<TComponent>& right);

    /*! \brief Subtract two Vector4
     *
     * \param left  The number to subtract to right
     * \param right The vector to subtract to left
     *
     * \return Return a vector resulting of an addition of this and right
     *
     */
    template<typename TComponent>
    Vector4<TComponent> operator-(float left, const Vector4<TComponent>& right);

    /*! \brief Subtract two Vector4
     *
     * \param left  The vector to subtract to right
     * \param right The number to subtract to left
     *
     * \return Return a vector resulting of an addition of this and right
     *
     */
    template<typename TComponent>
    Vector4<TComponent> operator-(const Vector4<TComponent>& left, float right);

    typedef Vector4<float> Vector4F;
    typedef Vector4<int> Vector4I;
    typedef Vector4<unsigned int> Vector4UI;
}

#include <Bull/Math/Vector/Vector4.inl>

#endif // Bull_Vector4_hpp
