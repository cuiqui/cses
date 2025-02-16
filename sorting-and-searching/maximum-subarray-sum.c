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


int main() {

    int n;
    ll xi;
    scanf("%d", &n);

    ll max, curr;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &xi);
        if (i == 0) {
            max = xi;
            curr = xi;
            continue;
        }
        curr = curr + xi > xi ? curr + xi : xi;
        max = curr > max ? curr : max;
    }
    printf("%lld\n", max);
    return 0;
}