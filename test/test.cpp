#include<iostream>
#include"MathCore/Concepts.hpp"
#include"MathCore/Vector3.hpp"

template<MathCore::isDecimalNumber T>
struct TestStruct{
    T value;
};

struct TestVector3{
    MathCore::Vector3<float> vec;
};

int main(){
    std::cout << "Vanguard math library init!\n";
    TestStruct<float> test{1.23};
    std::cout << "Float test passed: " << test.value << std::endl;
    TestVector3 testVec{MathCore::Vector3<float>()};
    std::cout << "Vector3 test passed: " << testVec.vec.x << ", " << testVec.vec.y << ", " << testVec.vec.z << " \n";
    testVec.vec = MathCore::Vector3<float>(1.f,2.f,3.f);
    std::cout << "Modified vector3 test passed: " << testVec.vec.x << ", " << testVec.vec.y << ", " << testVec.vec.z << " \n";
    return 0;
}