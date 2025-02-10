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

int a[200200];
int b[200200];

int main() {

    int n, m, k, applicant, building;
    scanf("%d %d %d", &n, &m, &k);

    for (int i = 0; i < n; i++) {
        scanf("%d", &applicant);
        a[i] = applicant;
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &building);
        b[i] = building;
    }
    
    sort(a, 0, n - 1);
    sort(b, 0, m - 1);

    int res = 0, i = 0, j = 0;
    while (i < n && j < m) {
        if (a[i] - k <= b[j] && b[j] <= a[i] + k) {
            i++;
            j++;
            res++;
        } else if (b[j] < a[i]) {
            j++;
        } else {
            i++;
        }
    }

    printf("%d\n", res);
    return 0;
}