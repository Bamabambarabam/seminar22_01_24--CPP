#include <iostream>
#include <cmath>
#include <cstdint>

using namespace std;

bool is_prime(int64_t x) {
    if (x == 1) {
        return true;
    }
    for (int64_t i = 2; i < int(sqrt(x)) + 1; ++i) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int a, b;
    cin >> a >> b;
    int *arr = new int[b - a + 1];
    uint32_t count = 0;
    for (int i = 1; i <= b; i++) {
        if (is_prime(i)) {
            arr[count] = i;
            count += 1;
        }
    }
    for (int i = 0; i < count; i++) {
        cout << arr[i] << " ";
    }
    delete[] arr;
    return 0;
}
