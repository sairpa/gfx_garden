#include <iostream>
#include <limits.h>
using namespace std;

// This is a program to find the max consecutive 1s in order

int check(int* arr, int s){
     
    int os[s/2];
    int pi=-1;
    int index = -1;
    int count = 0;
    
    int i=0;
    while(i < s){
        printf("arr i: %i, arr i+1:%i, pi:%i, count:%i\n",arr[i], arr[i+1], pi, count);
        if((arr[i] == 1) && (arr[i+1] == 1)){ // Consecutive 1s
            pi = i+1;
            ++i;
            ++count;
        }else{ // Not consecutive 1s or ender
            if(pi == i-1){ // End of the consecutive 1s
                ++index;
                os[index] = count;
            }else{
                count = 0;
            }
            ++i;
        }
    }

    int max = 0;
    for(int i=0; i< s/2;i++){
       if(os[i] > max) max = os[i]; 
    }

    cout << "Outputting the array for os\n";

    for(int i=0; i<s/2;i++){
        cout << os[i] << ", ";
    }

    cout << "\n";

    if(max == 0) return -1;
    else return max;
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

    cout <<"\n" << check(in,s);

    // cout << "Outputting the array! \n";

    // for(int i=0; i<s;i++){
    //     cout << in[i] << ", ";
    // }

    // cout <<"\n";

 }