#include <stdio.h>

#define N 4
#define W 5

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int i, j;

    int v[] = {0, 2, 4, 5, 6};
    int w[] = {0, 1, 2, 3, 4};

    int f[N + 1][W + 1] = {};

    for (i = 1; i <= N; i++) {
        for (j = 1; j <= W; j++) {
            if (j >= w[i]) {
                f[i][j] = max(f[i - 1][j], f[i - 1][j - w[i]] + v[i]);
            } else {
                f[i][j] = f[i - 1][j];
            }
        }
    }
    printf("%d\n", f[N][W]);

    return 0;
}