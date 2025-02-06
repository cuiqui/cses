#include <stdio.h>
typedef long long ll;

ll ceil(ll a, ll b) {
    ll div = a / b;
    ll mod = a % b;

    if (mod > 0) return div + 1;
    return div;
}

ll pow(int a, int b) {
    ll res = 1;
    while (b > 0) {
        res = res * (ll)(a);
        b--;
    }
    return res;
}


int main() {  
    int t;
    scanf("%d", &t);
    
    while (t--) {
        ll k;
        scanf("%lld", &k);

        int cifras = 1;
        ll cn = 9;

        while (k > (cn * cifras)) {
            k -= (cn * cifras);
            cifras++;
            cn *= 10;
        }
        
        ll num = pow(10, cifras - 1) - 1 + ceil(k, (ll)cifras);
        int dig = cifras - 1 - (k - 1) % cifras;

        while (dig--) {
            num /= 10;
        }
        printf("%lld\n", num % 10);
    }

    return 0;
}
