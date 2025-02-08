#include <stdio.h>
#include <string.h>
#define N 8

int block[N][N] = { 0 };
int a[N];

int es_sucesor(int k, int a_k) {
    if (block[k][a_k]) return 0;

    for (int j = 0; j < k; j++) {
        if (a[j] == a_k) return 0;

        int diff = a_k - a[j];
        if (diff == 0 || diff == k - j || diff == j - k) return 0;
    }
    return 1;
}

int count(int i) {
    if (i == N) return 1;

    int res = 0;
    for (int p = 0; p < N; p++) {
        if (es_sucesor(i, p)) {
            a[i] = p;
            res += count(i + 1);
            a[i] = -1;
        }
    }

    return res;
}


int main() {
    char s[N];
    memset(a, -1, sizeof(int) * N);

    for (int i = 0; i < N; i++) {
        scanf("%s", s);    
        for (int j = 0; j < N; j++) {
            if (s[j] == '*') block[i][j] = 1;
        }
    }

    printf("%d\n", count(0));

    return 0;
}
