#ifndef RECT_CLASS
#define RECT_CLASS
#include "Vec2.h"


template <typename T>
class Rect
{
public:
    Rect( const Vec2<T>& a, const Vec2<T>& b ) : a(a), b(b) {}
    Rect( const T Ax, const T Ay, const T Bx, const T By ) : a( Vec2<T>(Ax, Ay) ), b( Vec2<T>(Bx, By)) {}
    Rect( const Rect<T>& rhs ) : a(rhs.a), b(rhs.b) {}
    Rect& operator+( const Vec2<T> rhs )
    {
        a = a + rhs;
        b = b + rhs;
        return *this;
    }
    bool test( const Vec2<T> pos ) const
    {
        return (pos.x > a.x) && (pos.y > a.y) && (pos.x < b.x) && (pos.y < b.y);
    }
    bool test( const Rect<T> pos ) const
    {
        return false; //nao pensei em nada ainda
    }
public:
    Vec2<T> a;
    Vec2<T> b;
};

#endif