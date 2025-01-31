#include <stdio.h>


char s[1000100] = {0};


int main() {
    scanf("%s", s);

    int cnt = 1;
    int max = 1;
    for (int i = 1; s[i]; i++) {
        if (s[i-1] == s[i]) {
            cnt++;
            if (cnt > max) max = cnt;
        } else {
            cnt = 1;
        }
    }

    printf("%d\n", max);
}