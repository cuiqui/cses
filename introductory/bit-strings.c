#include <stdio.h>


typedef long long ll;


ll mul(ll a, ll b) {
    return (a * b) % 1000000007;
}


int main() {
    int n;
    scanf("%d", &n);

    ll s = 1;
    while (n > 0) {
        s = mul(s, 2);
        n--;
    }
    printf("%lld\n", s);
}