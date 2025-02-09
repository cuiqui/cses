#include <stdio.h>


typedef long long ll;
int seen[31250100] = { 0 };


int main() {
    int n;
    scanf("%d", &n);

    int res = 0;
    while (n--) {
        int c;
        scanf("%d", &c);

        int div = c / 32;
        int mod = c % 32;
        if (!((seen[div] >> 32 - mod) & 1)) {
            res++;
            int mark = 1 << (32 - mod);
            seen[div] |= mark;
        }
    }

    printf("%d\n", res);
}