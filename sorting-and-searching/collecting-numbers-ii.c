#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MS_T int


void merge(MS_T arr[], int l, int m1, int m2, int r, MS_T tmp[]) {
    while (l <= m1 && m2 <= r) *tmp++ = arr[l] < arr[m2] ? arr[l++] : arr[m2++];
    while (l <= m1) *tmp++ = arr[l++];
    while (m2 <= r) *tmp++ = arr[m2++];
}

void msort(MS_T arr[], int l, int r, MS_T tmp[]) {
    if (r <= l) return;
    int m = (l + r) / 2;
    msort(arr, l, m, tmp);
    msort(arr, m + 1, r, tmp);
    merge(arr, l, m, m + 1, r, tmp + l);
    memcpy(arr + l, tmp + l, (r - l + 1) * sizeof(MS_T));
}

void sort(MS_T arr[], int l, int r) {
    MS_T *tmp = (MS_T*)malloc((r - l + 1) * sizeof(MS_T));
    msort(arr, l, r, tmp);
    free(tmp);
}

int x[200200];
int p[200200];
int g[200200];
int n;
int rounds = 1;

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}


void update(int i) {
    if (i == 0 || i == n) return;
    if (p[i] < p[i-1] && g[i] == 0) {
        rounds++;
        g[i] = 1;
    }
    if (p[i] > p[i-1] && g[i] == 1) {
        rounds--;
        g[i] = 0;
    }
}


int main() {
    int m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x[i]);
        x[i]--;
        p[x[i]] = i;
    }

    for (int i = 1; i < n; i++) {
        if (p[i] < p[i-1]) {
            rounds++;
            g[i] = 1;
        }
    }

    while (m--) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;

        int i = x[a], j = x[b];
        swap(&x[a], &x[b]);
        swap(&p[i], &p[j]);

        update(i);
        update(i+1);
        update(j);
        update(j+1);
        
        printf("%d\n", rounds);
    }

    return 0;
}