#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MS_T int

typedef long long ll;

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


int p[200200];

int main() {

    int n;
    int pi;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }
    sort(p, 0, n - 1);

    ll diff = 0, mid = p[n>>1];
    for (int i = 0 ; i < n; i++) {
        int d = mid - p[i];
        diff += (d < 0 ? -d : d);
    }

    printf("%lld\n", diff);

    return 0;
}