#include <stdio.h>

typedef long long ll;


ll pow(int a, int b) {
    int res = 1;
    while (b > 0) {
        res = res * (ll)(a);
        b--;
    }
    return res;
}


int main() {
    int n;
    scanf("%d", &n);

    int f = 1;
    ll s = 0;
    while (pow(5, f) <= n) {
        s += n / (ll)(pow(5, f));
        f++;
    }
    printf("%lld\n", s);
}