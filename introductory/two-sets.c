#include <stdio.h>


typedef long long ll;


int main() {
    int n;
    scanf("%d", &n);

    int a[1000100] = {0};
    ll nn = ((ll)(n) * (n + 1)) >> 1;

    if (nn % 2 == 0) {
        printf("YES\n");
        ll k = nn >> 1;
        int c = 0;
        for (int i = n; i > 0; i--) {
            if ((k - i) >= 0) {
                a[i] = 1;
                k -= i;
                c++;
            }
        }
        printf("%d\n", c);
        for (int i = 1; i <= n; i++) {
            if (a[i]) {
                printf("%d ", i);
            }
        }
        printf("\n");
        printf("%d\n", n - c);
        for (int i = 1; i <= n; i++) {
            if (!a[i]) {
                printf("%d ", i);
            }
        }
    } else {
        printf("NO\n");
    }
}