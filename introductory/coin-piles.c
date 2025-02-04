#include <stdio.h>


typedef long long ll;


int abs(int a) {
    return a < 0 ? -a : a;
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int l, r;
        scanf("%d %d", &l, &r);

        int div = (l + r) % 3 == 0;
        int range = abs(l - r)  <= (l + r) / 3;
        
        if (div && range) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}