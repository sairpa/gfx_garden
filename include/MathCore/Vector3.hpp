#pragma once
#include<concepts>

namespace MathCore{

    template<isDecimalNumber T> struct Vector3{
        T x,y,z;
        constexpr Vector3():x(0), y(0), z(0) {}
        constexpr Vector3(T x, T y, T z):x(x), y(y), z(z) {}
    };

}