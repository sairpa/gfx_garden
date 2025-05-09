#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <climits>
#include <cstring>

using namespace std;

// Macros for convenience
#define fast_io ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
#define pb push_back
#define all(v) v.begin(), v.end()
#define pii pair<int, int>
#define vi vector<int>
#define vll vector<long long>
#define umap unordered_map
#define uset unordered_set

// Utility functions
template <typename T>
void printVector(const vector<T>& vec) {
    for (const auto& val : vec) {
        cout << val << " ";
    }
    cout << endl;
}

template <typename T>
void printMatrix(const vector<vector<T>>& mat) {
    for (const auto& row : mat) {
        for (const auto& val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

// Main function
int main() {
    fast_io;

    // Example: Input and output
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vi arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // Example: Sorting the array
    sort(all(arr));
    cout << "Sorted array: ";
    printVector(arr);

    // Example: Implement your algorithm here
    // ...

    return 0;
}
