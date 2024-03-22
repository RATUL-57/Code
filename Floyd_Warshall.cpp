#include <bits/stdc++.h>
using namespace std;

int INF = INT_MAX;

void printMatrix(int **matrix, int vertices);


void floydWarshall(int **graph, int vertices)
{
    int **matrix = new int *[vertices];
    for (int i = 0; i < vertices; ++i)
    {
        matrix[i] = new int[vertices];
        for (int j = 0; j < vertices; ++j)
        {
            matrix[i][j] = graph[i][j];
        }
    }

    for (int k = 0; k < vertices; ++k)
    {
        for (int i = 0; i < vertices; ++i)
        {
            for (int j = 0; j < vertices; ++j)
            {
                if (matrix[i][k] != INF && matrix[k][j] != INF && matrix[i][k] + matrix[k][j] < matrix[i][j])
                {
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
                }
            }
        }
    }
    printMatrix(matrix, vertices);
    for (int i = 0; i < vertices; ++i)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void printMatrix(int **matrix, int vertices)
{
    for (int i = 0; i < vertices; ++i)
    {
        for (int j = 0; j < vertices; ++j)
        {
            if (matrix[i][j] == INF)
                cout << "INF ";
            else
                cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
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
                graph[i][j] = INF;
        }
    }

    for (int i = 0; i < edges; ++i)
    {
        int vertex1, vertex2, weights;
        cin >> vertex1 >> vertex2 >> weights;

        graph[vertex1 - 1][vertex2 - 1] = weights;
        graph[vertex2 - 1][vertex1 - 1] = weights;
    }

    floydWarshall(graph, vertices);

    for (int i = 0; i < vertices; ++i)
    {
        delete[] graph[i];
    }
    delete[] graph;

    return 0;
}
