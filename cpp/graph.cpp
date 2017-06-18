#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void BreadthFirstSearch(int** graph, int visited[], int node, int vertices)
{
    queue<int> search_queue;
    search_queue.push(node);
    visited[node] = 1;

    while (!search_queue.empty()) {
        node = search_queue.front();
        search_queue.pop();
        cout << node << ' ';

        for (int i = 0; i < vertices; ++i) {
            if (visited[i] == 0 && graph[node][i] != 0) {
                search_queue.push(i);
                visited[i] = 1;
            }
        }
    }

    cout << endl;
}

void DFS(int** graph, int visited[], int node, int vertices)
{
    if (node < vertices) {
        cout << node << ' ';
        visited[node] = 1;

        for (int i = 0; i < vertices; ++i) {
            if (visited[i] == 0 && graph[node][i] != 0) {
                DFS(graph, visited, i, vertices);
            }
        }
    }
}

int main()
{
    int graph[][5] = {{0,1,1,1,0}, {0,0,0,1,1}, {0,0,0,0,1}, {0,0,0,0,1},
                     {0,0,0,0,0}};

    int* graph1[5];
    for (int i = 0; i < 5; ++i) {
        graph1[i] = graph[i];
    }

    int visited[5] = {0, 0, 0, 0, 0};
    int vertices = 5;

    BreadthFirstSearch(graph1, visited, 0, vertices);
    for (int i = 0; i < 5; ++i) {
        visited[i] = 0;
    }
    DFS(graph1, visited, 0, vertices);
    cout << endl;
    return 0;
}
