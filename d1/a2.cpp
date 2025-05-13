#include <iostream>
#include <limits.h>
using namespace std;

// This is a program to find the second largest element in the array

void check(int* arr, int s){
    int bn = INT_MIN;
    int sbn = INT_MIN;
    int sn = INT_MAX;
    int ssbn = INT_MAX;
    for(int i=0; i < s; i++){
        if(arr[i] > bn){
            sbn = bn;
            bn = arr[i];
        }else if((arr[i] > sbn) && (arr[i] != bn)){
            sbn = arr[i];
        }
        if(arr[i] < sn){
            ssbn = sn;
            sn = arr[i];
        }else if((arr[i] < ssbn) && (arr[i] != sn)){
            ssbn = arr[i];
        }
    }
    cout << "Second nums are: " << sbn << " ," << ssbn << " \n"; 
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

    check(in,s);

 }