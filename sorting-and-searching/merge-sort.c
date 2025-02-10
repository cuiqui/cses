#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void merge(int arr[], int l, int m1, int m2, int r, int tmp[]) {
    while (l <= m1 && m2 <= r) *tmp++ = arr[l] < arr[m2] ? arr[l++] : arr[m2++];
    while (l <= m1) *tmp++ = arr[l++];
    while (m2 <= r) *tmp++ = arr[m2++];
}

void msort(int arr[], int l, int r, int tmp[]) {
    if (l < r) {
        int m = (l + r) / 2;
        msort(arr, l, m, tmp);
        msort(arr, m + 1, r, tmp);
        merge(arr, l, m, m + 1, r, tmp + l);
        memcpy(arr + l, tmp + l, (r - l + 1) * sizeof(int));
    }
}

void sort(int arr[], int l, int r) {
    int *tmp = (int*)malloc((r - l) * sizeof(int));
    msort(arr, l, r, tmp);
    free(tmp);
}

int main() {
    int a[10000];
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int v;
        scanf("%d", &v);
        a[i] = v;
    }
    sort(a, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}