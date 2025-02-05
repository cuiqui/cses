#include <stdio.h>

typedef long long ll;
int n;
int p[20] = { 0 };


ll abs(ll a) {
    return a > 0 ? a : -a;
}

ll min(ll a, ll b) {
    return a > b ? b : a;
}


ll min_diff(int i, ll l, ll r) {
    if (i == n) {
        return abs(l - r);
    }

    return min(min_diff(i + 1, l + p[i], r), min_diff(i + 1, l, r + p[i]));
}


int main() {  
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }

    printf("%lld\n", min_diff(1, p[0], 0));

    return 0;
}
