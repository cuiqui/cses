#include <stdio.h>


int a[200100] = {0};


int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    long long incs = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] < a[i-1]) {
            incs += a[i-1] - a[i];
            a[i] = a[i-1];
        }
    }

    printf("%lld\n", incs);
}