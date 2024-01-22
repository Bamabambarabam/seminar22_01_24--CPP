#include <iostream>
#include <cmath>
#include <cstdint>
#include <algorithm>
#include <vector>

using namespace std;

void permutations(vector<double> arr){
    sort(arr.begin(), arr.end());

    do {
        for (double num : arr) {
            cout << num << " ";
        }
        cout << endl;
    } while (next_permutation(arr.begin(), arr.end()));
}

void permutations(vector<int> arr){
    sort(arr.begin(), arr.end());

    do {
        for (int num : arr) {
            cout << num << " ";
        }
        cout << endl;
    } while (next_permutation(arr.begin(), arr.end()));
}

int main() {
    uint32_t n;
    cin >> n;
    vector<double> arr_double;
    vector<int> arr_int(n);
    for(int i = 0; i < n; i++){
        double temp;
        cin >> temp;
        arr_double.push_back(temp);
    }
    if(arr_double[0] - int(arr_double[0]) != 0){
        permutations(arr_double);
    }else{
        for(int i = 0; i < n; i++){
            arr_int[i] = int(arr_double[i]);
        }
        permutations(arr_int);
    }
    return 0;
}
