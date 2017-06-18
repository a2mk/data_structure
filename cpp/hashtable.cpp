#include <stdio.h>

enum NodeStat {EMPTY, VALID, DELETED};

struct Node {
    int data;
    enum NodeStat stat;
};

int HashFunc(int data, int n)
{
    return data % n;
}

int Find(Node hashtable[], int data, int n)
{
    int key = HashFunc(data, n);
    int number = 0;
    while (hashtable[key].data != data && hashtable[key].stat != EMPTY) {
        key += ++number * 2 - 1;

        if (key >= n) {
            key -= n;
        }
    }
    return key;
}

void Insert(Node hashtable[], int data, int n)
{
    int key = Find(hashtable, data, n);
    if (hashtable[key].stat == VALID) {
        printf("data exist\n");
    } else {
        hashtable[key].data = data;
        hashtable[key].stat = VALID;
    }
}

void Delete(Node hashtable[], int data, int n)
{
    int key = Find(hashtable, data, n);
    if (hashtable[key].stat == VALID) {
        hashtable[key].stat = DELETED;
    } else {
        printf("data does not exist\n");
    }
}

int main()
{
    int n = 10;
    Node hashtable[n];
    for (int i = 0; i < n; ++i) {
        hashtable[i].data = 0;
        hashtable[i].stat = EMPTY;
    }

    Insert(hashtable, 10, n);
    Insert(hashtable, 20, n);
    Insert(hashtable, 30, n);
    Insert(hashtable, 51, n);
    Insert(hashtable, 10, n);
    Delete(hashtable, 98, n);
    Delete(hashtable, 30, n);
    Insert(hashtable, 40, n);

    for (int i = 0; i < n; ++i) {
        printf("position%d = %d, %d\n", i, hashtable[i].data, hashtable[i].stat);
    }
    return 0;
}
