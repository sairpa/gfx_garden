#include<iostream>
#include"MathCore/Concepts.hpp"

template<MathCore::isDecimalNumber T>
struct TestStruct{
    T value;
};

int main(){
    std::cout << "Vanguard math library init!\n";
    TestStruct<float> test{1.23};
    std::cout << "Float test passed: " << test.value << std::endl;
    return 0;
}