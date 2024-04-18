#include <stdio.h>
#include <math.h>


void mergeSort(int a[], int p, int r) {
    int q;
    if (p < r) {
        q = (p + r) / 2;
        mergeSort(a, p, q);
        mergeSort(a, q + 1, r);
        merge(a,p, q, r);
    }
}

void merge(int a[], int p, int q, int r) {

}