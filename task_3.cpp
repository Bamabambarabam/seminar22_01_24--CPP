#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;


bool check(string &str1, string &str2) {
    if (str1.length() != str2.length()) {
        return false;
    }
    unordered_map<char, int> freq_1;
    unordered_map<char, int> freq_2;

    for (char ch : str1) {
        freq_1[ch]++;
    }
    for (char ch : str2) {
        freq_2[ch]++;
    }
    return freq_1 == freq_2;
}

int main() {
    string str1;
    string str2;
    cin >> str1 >> str2;

    if (check(str1, str2)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}