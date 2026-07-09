#pragma once
#include<concepts>


namespace MathCore{
    template<typename T>
    concept isDecimalNumber = std::floating_point<T>;
}