#include <stdio.h>


typedef long long ll;


ll solve_for_n(int n) {
    ll nn = (ll)(n) * n;
    ll s = (nn * (nn - 1)) >> 1;
    ll r = 0;
    if (n == 3) {
        r = 8;
    } else if (n > 3) {
        r += 2 * 2 * (n - 2);
        r += 3 * 2 * (n - 2);
        r += 4 * (n - 4) * (n - 2);
        r += 4 + 2 * (n - 4);
    }
    return s - r;
}


int main() {
    int d;
    scanf("%d", &d);

    for (int n = 1; n <= d; n++) {
        printf("%lld\n", solve_for_n(n));
    }
}