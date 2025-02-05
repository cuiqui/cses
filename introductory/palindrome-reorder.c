#include <stdio.h>

typedef long long ll;

int main() {
    char a[1000100] = { 0 };
    int c[26] = { 0 };
    int len = 0;
    scanf("%s", a);

    for (int i = 0; a[i] != 0; i++) {
        c[a[i] - 'A']++;
        len++;
    }

    int l = 0, r = len - 1, odd_idx = -1;
    for (int i = 0; i < 26; i++) {
        if (c[i] % 2 == 1) {
            if (odd_idx != -1) {
                printf("NO SOLUTION\n");
                return 0;
            }
            odd_idx = i;
            continue;
        }

        while (c[i] > 0) {
            a[l++] = 'A' + i;
            a[r--] = 'A' + i;
            c[i] -= 2;
        }
    }

    for (; l <= r; l++) {
        a[l] = 'A' + odd_idx;
    }

    a[len] = '\0';
    printf("%s\n", a);

    return 0;
}