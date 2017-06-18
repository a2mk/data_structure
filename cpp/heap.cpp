// MinHeap implementation
#include <stdio.h>
#include <vector>
#include <stdexcept>
using namespace std;

void PercolateDown(vector<int>& a, int index)
{
    int n = a.size();
    int temp = a[index];
    while (2 * index + 1 < n) {
        int child = 2 * index + 1;
        if (child + 1 < n && a[child+1] < a[child]) {
            child = child + 1;
        }
        if (a[child] < temp) {
            a[index] = a[child];
            index = child;
        } else {
            break;
        }
    }
    a[index] = temp;
}

void PercolateUp(vector<int>& a, int index)
{
    int temp = a[index];
    while (index != 0) {
        int parent = (index - 1) / 2;
        if (a[parent] > temp) {
            a[index] = a[parent];
            index = parent;
        } else {
            break;
        }
    }
    a[index] = temp;
}

void Insert(vector<int>& a, int data)
{
    a.push_back(data);
    PercolateUp(a, a.size()-1);
}

int ExtractMin(vector<int>& a)
{
    if (a.empty()) {
        throw domain_error("empty heap");
    }
    int n = a.size();
    int ret = a[0];
    swap(a[0], a[n-1]);
    a.erase(a.end()-1);
    PercolateDown(a, 0);
    return ret;
}

void Build(vector<int>& a)
{
    int n = a.size();
    for (int i = n/2; i >=0; --i) {
        PercolateDown(a, i);
    }
}

int main()
{
    vector<int> a = {48, 99, 23, 87, 17, 48, 66, 103, 12, 7, 89, 13, 99, 48, 2, 12, 107,
                     87, 48, 203, 1, 22, 12, 99, 2, 48, 55, 103};
    Build(a);

    for (int i = 0; i < a.size(); ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");

    Insert(a, 15);
    for (int i = 0; i < a.size(); ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");

    while (!a.empty()) {
        int ret = ExtractMin(a);
        printf("min = %d\n", ret);
    }
    return 0;
}
