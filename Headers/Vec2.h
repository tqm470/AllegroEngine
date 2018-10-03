#ifndef VEC2_CLASS
#define VEC2_CLASS
#include <cmath>

template<typename T>
class Vec2
{
public:
    Vec2()
    {
        x = 0;
        y = 0;
    }
    Vec2( T x,T y )
        :
        x(x),
        y(y)
    {
    }
    Vec2( Vec2<T>& rhs )
    {
        x = rhs.x;
        y = rhs.y;
    }
    Vec2( const Vec2<T>& rhs )
    {
        x = rhs.x;
        y = rhs.y;
    }
    Vec2( const Vec2<T>&& rhs )
    {
        x = rhs.x;
        y = rhs.y;
    }
    Vec2<T> operator= ( const Vec2<T>&& rhs )
    {
        x = rhs.x;
        y = rhs.y;
    }
    Vec2<T> Normalizado() const
    {
        return *this / this->Comprimento();
    }

    double Comprimento() const
    {
        return sqrt( (x * x) + (y * y) );
    }

    Vec2<T> operator/ ( const T& rhs ) const
    {
        return {this->x / rhs, this->y / rhs};
    }
    Vec2<T> operator* ( const Vec2<T>& rhs ) const
    {
        return {this->x * rhs.x, this->y * rhs.y};
    }
    Vec2<T> operator* ( const T& rhs ) const
    {
        return {this->x * rhs, this->y * rhs};
    }
    Vec2<T> operator+ ( const Vec2<T>& rhs ) const
    {
        return {this->x + rhs.x, this->y + rhs.y};
    }
    Vec2<T> operator- ( const Vec2<T>& rhs ) const
    {
        return {this->x - rhs.x, this->y - rhs.y};
    }

    T x;
    T y;
};

#endif