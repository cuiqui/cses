#include <iostream>
#include <cstdint>
using namespace std;

uint64_t n;

int main() {
    cin >> n;

    while (n != 1) {
        cout << n << " ";
        if (n % 2 == 0) {
            n = n / 2;
        } else {
            n = 3 * n + 1;
        }
    }
    cout << 1 << endl;
    return 0;
}