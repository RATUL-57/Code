#include <bits/stdc++.h>
using namespace std;

#define INF 9999999

/*
int G[vertices][vertices] = {
    {0, 9, 75, 0, 0},
    {9, 0, 95, 19, 42},
    {75, 95, 0, 51, 66},
    {0, 19, 51, 0, 31},
    {0, 42, 66, 31, 0}
};
*/

void prim(int **G, int vertices) {
    int edge_count = 0;
    bool visited[vertices];
    memset(visited, false, sizeof(visited));
    
    visited[0] = true;
    int x, y;

    cout << "Edge"
         << " : "
         << "Weight";
    cout << endl;
    while (edge_count < vertices - 1) {
        int min = INF;
        x = 0;
        y = 0;
        for (int i = 0; i < vertices; i++) {
            if (visited[i]) {
                for (int j = 0; j < vertices; j++) {
                    if (!visited[j] && G[i][j]) {
                        if (min > G[i][j]) {
                            min = G[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        cout << x << " - " << y << " :  " << G[x][y] << endl;
        visited[y] = true;
        edge_count++;
    }
}

int main() {

    int vertices, edges;

    cin >> vertices >> edges;

    int **graph = new int *[vertices];

    for (int i = 0; i < vertices; ++i)
    {
        graph[i] = new int[vertices];
        for (int j = 0; j < vertices; ++j)
        {
            if (i == j)
                graph[i][j] = 0;
            else
                graph[i][j] = 0;
        }
    }

    for (int i = 0; i < edges; ++i)
    {
        int vertex1, vertex2, weights;
        cin >> vertex1 >> vertex2 >> weights;

        graph[vertex1 - 1][vertex2 - 1] = weights;
        graph[vertex2 - 1][vertex1 - 1] = weights;
    }

    prim(graph,vertices);
    return 0;
}
