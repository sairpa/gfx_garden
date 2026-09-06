#pragma once
#include <concepts>
#include "Vector3.hpp"

namespace MathCore{
    template<isDecimalNumber T> struct Vector4{
        T w,x,y,z;

        constexpr Vector4():w(0), x(0), y(0), z(0) {};
        constexpr Vector4(T w, T x, T y, T z):w(w), x(x), y(y), z(z) {};
        constexpr Vector4(const Vector3<T>&i, T w):w(w), x(i.x), y(i.y), z(i.z) {};

        // Operations
        constexpr Vector4<T> operator+(const Vector4<T>& i) const{
            return Vector4<T>(w+i.w, x+i.x, y+i.y, z+i.z);
        }

        constexpr Vector4<T> operator-(const Vector4<T>& i) const{
            return Vector4<T>(w-i.w, x-i.x, y-i.y, z-i.z);
        }

        // Scalar return
        constexpr T dot(const Vector4<T>& i)const {
            return (x*i.x) + (y*i.y) + (z*i.z) + (w*i.w);
        }

        // Vector return doesn't exist other than in 3D and 7D :p
        
    };
}