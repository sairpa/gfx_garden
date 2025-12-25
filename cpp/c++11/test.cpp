#include<bits/stdc++.h>
using namespace std;

// My test code snippet collection to learn c11 standards
// g++ -std=c++11 /home/tintu/dev/gfx_garden/cpp/c++11/test.cpp -o test; ./test

int main(){

    // Code for range based iterator
    // {
    //     vector<int> list = {1,2,3,4};

    //     for(int i:list){
    //         cout << i << " ";
    //     }
    //     cout << endl;
    // }


    //  lambda expressions
    // {
    //     auto res = [](int x){
    //         return x*x;
    //     };

    //     cout << res(5) << endl;
    //     cout << res(0) << endl;
    // }

    // Smart pointers
    {
        // we have an auto_ptr but is depreciated in c17 so not needed but essentially 
        // it is a smart auto allocate and deallocate pointer architecture but is phased out due to better impls
        // instead now we have unique, shared and weak pointers- unique_ptr shared_ptr weak_ptr
        // unique_ptr<int> k(new int(13));
        // cout << *k << endl;

        // unique_ptr<int> p;
        // p = move(k);
        // cout << (k == nullptr) << " ," << *p << endl;


        // shared_ptr<int> l,l0(new int(13));
        // l = l0;
        // cout << *l << *l0 << l0.use_count() << endl;

        // weak_ptr<int> l1(l0);
        // cout << *l0 << l1.use_count() << l0.use_count() << endl;

    }

    // Move semantics :D
    // helps move/transfer ownership of objects instead of redundantly copying
    // copy( creates duplicate, holds the orignal object, slower and intensive per usage)
    // move (transfers ownership, deletes the orignal object, faster io)
    {
        // string k,s(" Hello!");
        // k = move(s);
        // cout << k << s << endl;
        // Expression semantics
        // lvalue, rvalue T& and T&&
        // lvalue -> actual solid reference to value and the physical memory address/location 
        // updates 
        // int x = 13;
        // int& ref = x;
        // ref = 20;
        // cout << x << "\t" << ref << endl;
        // rvalue -> binds to temporary references/objects/values
        // int x = 10;
        // int&& y1 = 13;
        // cout << x << "\t" << y1 << endl;
    }

    // constexpr
    // compile time evaluation and helps runtime performance
    // 


    return 0;
}