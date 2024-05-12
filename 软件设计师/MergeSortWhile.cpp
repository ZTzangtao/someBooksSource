#include <stdio.h>
// #include <sched.h>

void Merge1(int A[], int p, int q, int r) {
    int n1 = q - p + 1, n2 = r - q, i, j, k;
    int L[50], R[50];
    for (i = 0; i < n1; i++) {
        L[i] = A[p + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = A[q + j +1];
    }
    L[n1] = 5000;
    R[n2] = 5000;
    i = 0;
    j = 0;
    for (k = p; k < r + 1; k++) {
        if (L[i] < R[j]) {
            // 小的放前面
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    }
}

void mergeSort(int A[], int p, int r) {
    int q;
    if (p < r) {
        q = (p + r) / 2;
        mergeSort(A, p, q);
        mergeSort(A, q + 1, r);
        Merge1(A, p, q, r);
    }
}



int main() {
    int A[] = {4, 1, 3, 45, 46, 5};
    mergeSort(A, 0, 5);
    int i;
    for (i = 0; i <= 5; i++) {
        printf("%d ", A[i]);
    }
    return 0;
}