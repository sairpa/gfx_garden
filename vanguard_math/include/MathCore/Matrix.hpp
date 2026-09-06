#pragma once
#include "Concepts.hpp"
#include "Vector3.hpp"

namespace MathCore{

    template<isDecimalNumber T> struct Matrix4x4{
        Vector4<T> c0, c1, c2, c3;
        constexpr Matrix4x4():c1(1,0,0,0),c1(0,1,0,0),c2(0,0,1,0),c3(0,0,0,1){};

        static constexpr Matrix4x4 translate(const Vector3<T>& translation){
            Matrix4x4 m;
            m.c3.x = translation.x;
            m.c3.y = translation.y;
            m.c3.z = translation.z;
            return m;
        }
    };

}