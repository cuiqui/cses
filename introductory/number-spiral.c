#include <stdio.h>


typedef long long ll;

int main() {
    int t, i, j;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &i, &j);

        int max = i > j ? i : j;
        ll n = (ll)(max - 1) * (max - 1);

        if (max % 2 == 0) {
            n += (ll)(i);
            if (i > j) n += (i - j);
        } else {
            n += (ll)(j);
            if (i < j) n += (j - i);
        }

        printf("%lld\n", n);
    }
}