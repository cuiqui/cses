#include <iostream>
#include <cstdint>
using namespace std;


int main() {
    
    int n;
    cin >> n;

    int sum = 0;
    for (int i = 0; i <= n; i++) {
        sum ^= i;
    }

    int x;
    for (int i = 0; i < n - 1; i++){ 
        cin >> x;
        sum ^= x;
    }
    cout << sum << endl;
}