#include <stdio.h>
#include <math.h>

#define N 4

int q[N + 1]; // 存储皇后的列�?

int check(int j) {
    int i;
    for (i = 1; i < j; i ++) {
        if (q[i] == q[j] || abs(i - j) == abs(q[i] - q[j])) {
            // 判断是否在同一列和同一斜线�?
            return 0;
        }
    }
    return 1;
}

void queen () {
    // 求解 N 皇后方案
    int i;
    for (i = 1; i <= N; i++) {
        q[i] = 0;
    }
    // 方案�?
    int answer = 0;
    
    // 表示正在摆放�? j 个皇�?
    int j = 1;
    while (j >= 1) {
        q[j] = q[j] + 1;
        // 判断�? j 个皇后的位置是否合法
        while (q[j] <= N && !check(j)) {
            // 不合法就往后挪一个位�?
            q[j] = q[j] + 1;
        }
        
        if(q[j] <= N) {
            // 表示�? j 个皇后的找到一个合法的摆放位置
            if (j == N) {
                // 找到�? N 皇后的一组解
                answer = answer + 1;
                printf("方案%d: ", answer);

                for (i = 1; i <= N; i++) {
                    printf("%d ", q[i]);
                }
                printf("\n");

            } else {
                // 继续摆放下一个皇�?
                j = j + 1;
            }
        } else {
            // 还原�? j 个皇后的位置
            q[j] = 0;
            // 表示�? j 个皇后找不到一个合法的位置
            j = j  - 1;
        }
    }

}


int main () {
    queen();
    return 0;
}