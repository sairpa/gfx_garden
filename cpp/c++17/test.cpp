#include<bits/stdc++.h>
using namespace std;

// C++ 17 Standards dive :D

// namespace Game::Graphics::UI{
//     void startup(){
//         // ops for gameui
//         cout << "Whatever!\n";
//     }
//     void display(){
//         cout << "GAME UI Init\n";
//         startup();
//     }
// }

// template<typename... Args>
// auto SumWithOne(Args... args){
//     return (10 + ... + args);
// }

// int var = 100;

int main(int argc, char** argv){

    // Nested namespaces
    // Game::Graphics::UI::display();

    // Tuple unpacking with auto
    // tuple<int,string> s = make_tuple(1,"rpa");
    // auto [id,name]{s};
    // cout << id << "\t" << name << endl;

    // cout << SumWithOne(-10) << endl;

    // inline variables
    
    // cout << var << endl;


    // Any datatype
    // any p{13};
    // cout << p.has_value() << "\t" << p.type().name() << "\t" << any_cast<int>(p) << endl;

    // variant<int, string, double> v{"rpa"};
    // cout << get<string>(v) << endl;

    string_view sv{"This is a string view in c++17"};
    cout << sv << "\t" << sv.size() << endl;

    return 0;
}