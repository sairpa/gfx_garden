#include <iostream>
using namespace std;

// This is a program to left rotate an array!

int* left_rotate(int* arr,int d){
    
    int x = arr[0];
    cout << arr[0] << ", " << x << "\n";

    for(int i=0;i <d-1; i++){
        arr[i] = arr[i + 1];
    }
    arr[d-1] = x;
    return arr;
}


int main(){
    // Get the input array
    int s;
    cout<< "Size: ";
    cin >> s;
    cout<< "\n";
    int in[s];
    cout<< "Enter the array now: ";
    for(int i=0; i<s; i++){
        int k;
        cin >> k;
        in[i] = k; 
    }

    cout << "Outputting the array! \n";

    for(int i=0; i<s;i++){
        cout << in[i] << ", ";
    }

    cout <<"\n";


    // Actual rotating the array!

    left_rotate(in,s);

    cout << "Outputting the array! \n";

    for(int i=0; i<s;i++){
        cout << in[i] << ", ";
    }

    cout <<"\n";

 }