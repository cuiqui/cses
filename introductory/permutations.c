#include <stdio.h>


int main() {
    int n;
    scanf("%d", &n);

    if (n == 2 || n == 3) {
        printf("NO SOLUTION\n");
        return 0;
    }

    int si = 1;
    int sj = 2;
    if (n % 2 == 0) {
        si = 2;
        sj = 1;
    }
    for (si; si <= n; si += 2) {
        printf("%d ", si);
    }
    for (sj; sj <= n; sj += 2) {
        printf("%d ", sj);
    }

}