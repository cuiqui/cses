#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void merge(int arr[], int l, int m1, int m2, int r, int tmp[]) {
    while (l <= m1 && m2 <= r) *tmp++ = arr[l] < arr[m2] ? arr[l++] : arr[m2++];
    while (l <= m1) *tmp++ = arr[l++];
    while (m2 <= r) *tmp++ = arr[m2++];
}

void msort(int arr[], int l, int r, int tmp[]) {
    if (r <= l) return;
    int m = (l + r) / 2;
    msort(arr, l, m, tmp);
    msort(arr, m + 1, r, tmp);
    merge(arr, l, m, m + 1, r, tmp + l);
    memcpy(arr + l, tmp + l, (r - l + 1) * sizeof(int));
}

void sort(int arr[], int l, int r) {
    int *tmp = (int*)malloc((r - l + 1) * sizeof(int));
    msort(arr, l, r, tmp);
    free(tmp);
}

int p[200200];

int main() {

    int n, x, pi;
    scanf("%d %d", &n, &x);

    for (int i = 0; i < n; i++) {
        scanf("%d", &pi);
        p[i] = pi;
    }
    
    sort(p, 0, n - 1);

    int res = 0, i = 0, j = n - 1;
    while (i < j) {
        if (p[i] + p[j] <= x) {
            i++;
            j--;
            res++;
        } else {
            j--;
            res++;
        }
        if (i == j) res++;
    }

    printf("%d\n", res);
    return 0;
}