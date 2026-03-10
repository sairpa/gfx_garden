#include<bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]){
    vector<int> con{1,2,3,4};

    auto k = [&con](){
        int j=0;
        for(int i:con){
            j += i;
        }
        cout << j << endl;
    };

    k();


    return 0;
}