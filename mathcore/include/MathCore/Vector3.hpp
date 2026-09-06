#pragma once
#include<concepts>

namespace MathCore{

    template<isDecimalNumber T> struct Vector3{
        T x,y,z;
        constexpr Vector3():x(0), y(0), z(0) {}
        constexpr Vector3(T x, T y, T z):x(x), y(y), z(z) {}

        // Operations 

        constexpr Vector3<T> operator+(const Vector3<T>& i) const{
            return Vector3<T>(x+i.x, y+i.y, z+i.z);
        }

        constexpr Vector3<T> operator-(const Vector3<T>& i)const{
            return Vector3<T>(x-i.x, y-i.y, z-i.z);
        }

        // Scalar Arg and Scalar Return
        constexpr T dot(const Vector3& i) const{
            return (x*i.x) + (y*i.y) + (z*i.z);
        }

        // Cross Product - Vector Return
        // Surface Normal math
        constexpr Vector3<T> cross(const Vector3& i) const{
            return Vector3<T>(
                (y*i.z) - (z*i.y), 
                (z*i.x) - (x*i.z), 
                (x*i.y) - (y*i.x)
            );
        }

    };

}