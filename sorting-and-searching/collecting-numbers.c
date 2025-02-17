#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MS_T perm_t

typedef struct perm_s {
    int val;
    int idx;
} perm_t;


void merge(MS_T arr[], int l, int m1, int m2, int r, MS_T tmp[]) {
    while (l <= m1 && m2 <= r) *tmp++ = arr[l].val < arr[m2].val ? arr[l++] : arr[m2++];
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

perm_t perm[200200];

int main() {

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &perm[i].val);
        perm[i].idx = i;
    }
    
    sort(perm, 0, n - 1);

    int rounds = 1;
    for (int i = 1; i < n; i++) {
        if (perm[i].idx < perm[i-1].idx) rounds++;
    }

    printf("%d\n", rounds);
    return 0;
}