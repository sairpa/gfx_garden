#include<iostream>
#include"MathCore/Concepts.hpp"
#include"MathCore/Vector3.hpp"
#include"MathCore/Vector4.hpp"


int main(){
    std::cout << "Vanguard math library init!\n";
    
    // Vector 3 Impl testing
    // {
    //     MathCore::Vector3<float> v1(1.0f, 0.f, 0.f);
    //     MathCore::Vector3<float> v2(0.f, 1.f, 0.f);
        
    //     std::cout << "Vector 3 Test Cases:\n";

    //     MathCore::Vector3<float> addRes = v1 + v2;
    //     std::cout << "Vector3 addition test passed: " << addRes.x << ", " << addRes.y << ", " << addRes.z << " \n";

    //     MathCore::Vector3<float> subRes = v1 - v2;
    //     std::cout << "Vector3 subtraction test passed: " << subRes.x << ", " << subRes.y << ", " << subRes.z << " \n";

    //     MathCore::Vector3<float> crossRes = v1.cross(v2);
    //     std::cout << "Vector3 cross product test passed: " << crossRes.x << ", " << crossRes.y << ", " << crossRes.z << " \n";

    //     float dotRes = v1.dot(v2);
    //     std::cout << "Vector3 dot product test passed: " << dotRes << " \n";
    // }

    // Vector 4 Impl testing
    {
        std::cout << "Vector 4 Test Cases:\n";
        MathCore::Vector3<float> v1(1.,2.,3.), v2(4.,5.,6.);
        MathCore::Vector4<float> v3(v2,1.), v4(7.,8.,9.,10.);

        MathCore::Vector4<float> sumRes = v3 + v4;
        std::cout << "Vector 4 Sum Results: " << sumRes.x << ", " << sumRes.y << ", " << sumRes.z << ", " << sumRes.w << "\n";

        MathCore::Vector4<float> subRes = v4 - v3;
        std::cout << "Vector 4 Sub Results: " << subRes.x << ", " << subRes.y << ", " << subRes.z << ", " << subRes.w << "\n";

        float dotRes = v3.dot(v4);
        std::cout << "Vector 4 Dot Results: " << dotRes << "\n";
    }


    return 0;
}