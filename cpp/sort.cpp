#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

void Bubble(int a[], int n)
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (a[j] > a[j+1]) {
                swap(a[j], a[j+1]);
            }
        }
    }
}

void Select(int a[], int n)
{
    for (int i = 0; i < n; ++i) {
        int temp = i;
        for (int j = i; j < n; ++j) {
            if (a[j] < a[temp]) {
                temp = j;
            }
        }
        swap(a[i], a[temp]);
    }
}

void Insert(int a[], int n)
{
    for (int i = 0; i < n; ++i) {
        int temp = a[i];
        int j;
        for (j = i; j > 0; --j) {
            if (a[j-1] > temp) {
                a[j] = a[j-1];
            } else {
                break;
            }
        }
        a[j] = temp;
    }
}

void PercolateDown(int a[], int index, int n)
{
    int temp = a[index];
    while (2 * index + 1 < n) {
        int child = 2 * index + 1;
        if (child + 1 < n && a[child+1] > a[child]) {
            child = child + 1;
        }
        if (a[child] > temp) {
            a[index] = a[child];
            index = child;
        } else {
            break;
        }
    }

    a[index] = temp;
}

void Heap(int a[], int n)
{
    for (int i = n / 2; i >= 0; --i) {
        PercolateDown(a, i, n);
    }
    for (int i = n - 1; i > 0; --i) {
        swap(a[0], a[i]);
        PercolateDown(a, 0, i);
    }
}

void Merge(int a[], int temp[], int leftbegin, int leftend, int rightend)
{
    int rightbegin = leftend + 1;
    int tempbegin = leftbegin;
    int size = rightend - leftbegin + 1;

    while (leftbegin <= leftend && rightbegin <= rightend) {
        if (a[leftbegin] <= a[rightbegin]) {
            temp[tempbegin] = a[leftbegin];
            leftbegin++;
        } else {
            temp[tempbegin] = a[rightbegin];
            rightbegin++;
        }
        tempbegin++;
    }

    while (leftbegin <= leftend) {
        temp[tempbegin++] = a[leftbegin++];
    }

    while (rightbegin <= rightend) {
        temp[tempbegin++] = a[rightbegin++];
    }

    for (int i = 0; i < size; ++i) {
        a[rightend] = temp[rightend];
        rightend--;
    }
}


void MergeSort(int a[], int temp[], int begin, int end)
{
    if (begin < end) {
        int mid = (begin + end) / 2;
        MergeSort(a, temp, begin, mid);
        MergeSort(a, temp, mid+1, end);
        Merge(a, temp, begin, mid, end);
    }
}

void Quick(int a[], int begin, int end)
{
    if (begin < end) {
        int pivot = a[begin];
        int i = begin+1;
        int j = end;
        while (true) {
            while (i <= end && a[i] < pivot) {
                i++;
            }
            while (j > begin && a[j] > pivot) {
                j--;
            }
            if (i < j) {
                swap(a[i], a[j]);
                i++;
                j--;
            } else {
                break;
            }
        }

        swap(a[begin], a[j]);
        Quick(a, begin, j-1);
        Quick(a, j+1, end);
    }
}

int main()
{
    int a1[] = {48, 99, 23, 87, 17, 48, 66, 103, 12, 7, 89, 13, 99, 48, 2, 12, 107, 87, 48,
               203, 1, 22, 12, 99, 2, 48, 55, 103};
    int a2[] = {48, 99, 23, 87, 17, 48, 66, 103, 12, 7, 89, 13, 99, 48, 2, 12, 107, 87, 48,
               203, 1, 22, 12, 99, 2, 48, 55, 103};
    int a3[] = {48, 99, 23, 87, 17, 48, 66, 103, 12, 7, 89, 13, 99, 48, 2, 12, 107, 87, 48,
               203, 1, 22, 12, 99, 2, 48, 55, 103};
    int a4[] = {48, 99, 23, 87, 17, 48, 66, 103, 12, 7, 89, 13, 99, 48, 2, 12, 107, 87, 48,
               203, 1, 22, 12, 99, 2, 48, 55, 103};
    int a5[] = {48, 99, 23, 87, 17, 48, 66, 103, 12, 7, 89, 13, 99, 48, 2, 12, 107, 87, 48,
               203, 1, 22, 12, 99, 2, 48, 55, 103};
    int a6[] = {48, 99, 23, 87, 17, 48, 66, 103, 12, 7, 89, 13, 99, 48, 2, 12, 107, 87, 48,
               203, 1, 22, 12, 99, 2, 48, 55, 103};
    int n = sizeof(a1)/sizeof(int);
    Bubble(a1, n);
    Select(a2, n);
    Insert(a3, n);
    Heap(a4, n);
    int temp[n];
    MergeSort(a5, temp, 0, n - 1);
    Quick(a6, 0, n - 1);

    for (int i = 0; i < n; ++i) {
        printf("%d ", a1[i]);
    }
    printf("\n");

    for (int i = 0; i < n; ++i) {
        printf("%d ", a2[i]);
    }
    printf("\n");

    for (int i = 0; i < n; ++i) {
        printf("%d ", a3[i]);
    }
    printf("\n");

    for (int i = 0; i < n; ++i) {
        printf("%d ", a4[i]);
    }
    printf("\n");

    for (int i = 0; i < n; ++i) {
        printf("%d ", a5[i]);
    }
    printf("\n");

    for (int i = 0; i < n; ++i) {
        printf("%d ", a6[i]);
    }
    printf("\n");

    return 0;
}
