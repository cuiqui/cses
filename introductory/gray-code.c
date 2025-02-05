#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;

int main() {
    scanf("%d", &n);
    
    int **a = malloc((1 << n) * sizeof(int *));

    for (int i = 0; i < (1 << n); i++) {
        a[i] = calloc(n, sizeof(int));
    }

    for (int j = n - 1; j >= 0; j--) {
        int mid = 1 << (n - j - 1);
        for (int i = 0; i < (1 << (n - j)); i++) {
            if (i >= mid) {
                memcpy(a[i], a[mid - (i - mid + 1)], n * sizeof(int));
                a[i][j] = 1;
            }
        }
    }


    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            printf("%d", a[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < (1 << n); i++) {
        free(a[i]);
    }
    free(a);
}
