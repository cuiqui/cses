
#define N 7
#include <stdio.h>

int seen[N][N] = { 0 };
int di[4] = { -1, 1,  0, 0 };
int dj[4] = {  0, 0, -1, 1 };
int ci[8] = { -1, -1,  0,  1, 1, 1, 0, -1 };
int cj[8] = {  0, -1, -1, -1, 0, 1, 1,  1 };
char s[N * N] = { 0 };
char dirs[4] = { 'U', 'D', 'L', 'R' };


int viable(int i, int j) {
    return 0 <= i && i < N && 0 <= j && j < N && !seen[i][j];
}


int count(int i, int j, int n) {
    // Poda 1: caso base. Si llegué al cuadrado de abajo
    // a la izquierda me fijo si soy hamiltoniano.
    if (i == N - 1 && j == 0) return n == N * N - 1;

    // Poda 2: si la cantidad de casillas que me faltan
    // visitar son menores a la distancia al final.
    if (N * N - n - 1 < j + (6 - i)) return 0;

    // Poda 3: si encerré un área.
    int fases = 0;
    for (int k = 0; k < 8; k++) {
        int i1 = i + ci[k],       j1 = j + cj[k];
        int i2 = i + ci[(k+1)%8], j2 = j + cj[(k+1)%8];
        fases += (viable(i1, j1) != viable(i2, j2));
    }
    if (fases > 2) return 0;

    int res = 0;
    for (int k = 0; k < 4; k++) {
        int ii = i + di[k], jj = j + dj[k];

        if (!viable(ii, jj)) continue;
        if (s[n] != '?' && s[n] != dirs[k]) continue;

        seen[ii][jj] = 1;
        res += count(ii, jj, n + 1);
        seen[ii][jj] = 0;
    }

    return res;
}


int main() {  
    scanf("%s", s);

    seen[0][0] = 1;
    printf("%d\n", count(0, 0, 0));
    seen[0][0] = 0;

    return 0;
}
