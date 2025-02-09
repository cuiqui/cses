#include <stdio.h>


void solve(int n, int a, int b) {
    if (n == 1) {
        printf("%d %d\n", a, b);
    } else {
        solve(n - 1, a, 6 - a - b);
        printf("%d %d\n", a, b);
        solve(n - 1, 6 - a - b, b);
    }
}


int main() {
    int n;
    scanf("%d", &n);

    printf("%d\n", (1 << n) - 1);
    solve(n, 1, 3);
    return 0;
}
