#include <stdio.h>
#include <math.h>

#define N 10

int answer = 0;

int q[N + 1]; 

int check(int j) {
    int i;
    for (i = 1; i < j; i ++) {
        if (q[i] == q[j] || abs(i - j) == abs(q[i] - q[j])) {
            return 0;
        }
    }
    return 1;
}

void queen(int j) {
    int i;
    for (i = 1; i <= N; i++) {
        q[j] = i;
        if (check(j)) {
            if (j == N) {
                answer = answer + 1;
                printf("answer%d: ", answer);

                for (i = 1; i <= N; i++) {
                    printf("%d ", q[i]);
                }
                printf("\n");
            } else {
                queen(j + 1);
            }
        }
    }
}

int main () {
    queen(1);
    return 0;
}