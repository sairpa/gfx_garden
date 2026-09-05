#include<iostream>
#include"MathCore/Concepts.hpp"
#include"MathCore/Vector3.hpp"


int main(){
    std::cout << "Vanguard math library init!\n";
    
    MathCore::Vector3<float> v1(1.0f, 0.f, 0.f);
    MathCore::Vector3<float> v2(0.f, 1.f, 0.f);
    
    MathCore::Vector3<float> addRes = v1 + v2;
    std::cout << "Vector3 addition test passed: " << addRes.x << ", " << addRes.y << ", " << addRes.z << " \n";

    MathCore::Vector3<float> subRes = v1 - v2;
    std::cout << "Vector3 subtraction test passed: " << subRes.x << ", " << subRes.y << ", " << subRes.z << " \n";

    MathCore::Vector3<float> crossRes = v1.cross(v2);
    std::cout << "Vector3 cross product test passed: " << crossRes.x << ", " << crossRes.y << ", " << crossRes.z << " \n";

    float dotRes = v1.dot(v2);
    std::cout << "Vector3 dot product test passed: " << dotRes << " \n";

    return 0;
}