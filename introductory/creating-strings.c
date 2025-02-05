#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char s[8] = { 0 };
int c[26] = { 0 };


int factorial(int n) {
    int s = 1;
    while (n > 0) {
        s *= n;
        n--;
    }
    return s;
}


int lines() {
    int num = factorial(strlen(s));
    int den = 1;
    for (int i = 0; i < 26; i++) {
        if (c[i] > 0) {
            den *= factorial(c[i]);
        }
    }
    return num / den;
}


void permutations(int i) {
    if (i == strlen(s)) {
        printf("%s\n", s);
        return;
    }

    for (int j = 0; j < 26; j++) {
        if (c[j] > 0) {
            s[i] = j + 'a';
            c[j]--;
            permutations(i + 1);
            c[j]++;
        }
    }
}


int main() {
    scanf("%s", s);
    
    for (int i = 0; s[i] != 0; i++) {
        c[s[i] - 'a']++;
    }

    printf("%d\n", lines());
    permutations(0);
    return 0;
}
