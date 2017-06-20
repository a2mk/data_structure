#include <stdio.h>

int bsearch(int a[], int val, int n)
{
    int i = 0;
    int j = n - 1;
    while (i <= j) {
        int mid = (i + j) / 2;
        if (a[mid] == val) {
            return mid;
        } else if (a[mid] < val) {
            i = mid + 1;
        } else {
            j = mid - 1;
        }
    }
    return -1;
}

int bsearch1(int a[], int val, int left, int right)
{
    if (left <= right) {
        int mid = (left + right) / 2;
        if (a[mid] == val) {
            return mid;
        } else if (a[mid] < val) {
            return bsearch1(a, val, mid+1, right);
        } else {
            return bsearch1(a, val, left, mid-1);
        }
    } else {
        return -1;
    }
}

int main()
{
    int a[] = {1, 3, 5, 10, 17, 23};
    printf("iteration binary search = %d\n", bsearch(a, 17, 6));
    printf("recursion binary search = %d\n", bsearch1(a, 3, 0, 5));
    printf("iteration binary search = %d\n", bsearch(a, 2, 6));
    printf("recursion binary search = %d\n", bsearch1(a, 45, 0, 5));
}
