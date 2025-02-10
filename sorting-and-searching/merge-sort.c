#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void merge(int arr[], int l, int m, int r, int tmp[]) {
    int i = l, j = m + 1;
    while (l <= m && j <= r) tmp[i++] = arr[l] < arr[j] ? arr[l++] : arr[j++];
    while (l <= m) tmp[i++] = arr[l++];
    while (j <= r) tmp[i++] = arr[j++];
}

void msort(int arr[], int l, int r, int tmp[]) {
    if (l < r) {
        int m = (l + r) / 2;
        msort(arr, l, m, tmp);
        msort(arr, m + 1, r, tmp);
        merge(arr, l, m, r, tmp);
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