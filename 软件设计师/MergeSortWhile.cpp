#include <stdio.h>
#include <sched.h>


void mergeSort(int a[], int p, int r) {
    int q;
    if (p < r) {
        q = (p + r) / 2;
        mergeSort(a, p, q);
        mergeSort(a, q + 1, r);
        merge(a,p, q, r);
    }
}

void merge(int A[], int p, int q, int r) {
    int n1 = q - p + 1, n2 = r - q, i, j, k;
    int L[50], R[50];
    for (i = 0; i < n1; i++) {
        L[i] = A[p + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = A[q + j +1];
    }
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;
    i = 0;
    j = 0;
    for (k = p; k < r + 1; k++) {
        if (L[i] < R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    }
}