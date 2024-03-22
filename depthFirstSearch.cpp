#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back
#define mp make_pair

#define Fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


void DFS_by_adjacencyList(vector<vector<int>>& adjacencyList, int index, vector<bool>& visited) {
    visited[index] = true; 
    cout << index+1 << " "; 

    for (int i = 0; i < adjacencyList[index].size(); ++i) {
        if (!visited[adjacencyList[index][i]])
            DFS_by_adjacencyList(adjacencyList, adjacencyList[index][i], visited);
    }
}


void DFS_by_adjacencyMatrix(vector<vector<int>>adjacencyMatrix, int index, vector<bool>& visited) {
    visited[index] = true; 
    cout << index+1 << " "; 

    for (int i = 0; i < adjacencyMatrix[index].size(); ++i) {
        if (!visited[i] && adjacencyMatrix[index][i] != 0)
            DFS_by_adjacencyMatrix(adjacencyMatrix, i, visited);
    }
}


int main()
{
    Fast;

    // int n, m, i;
    // cin >> n >> m;

    // vector<vector<int>>adjacencyList(n);
    // vector<bool>visited(n,false);

    // for(i=0; i<m;i++)
    // {
    //     int a, b;
    //     cin >> a >> b;
    //     adjacencyList[a-1].pb(b-1);
    //     adjacencyList[b-1].pb(a-1);
    // }

    // DFS_by_adjacencyList(adjacencyList,0,visited);




    int n, m;

    cin >> n >> m;

    
    vector<vector<int>>adjacencyMatrix(n,vector<int>(n,0));
    vector<bool> visited(n,false);

    for(int i=0;i<m;i++)
    {
        int a, b;
        cin >> a >> b;
        adjacencyMatrix[a-1][b-1] = 1;
        adjacencyMatrix[b-1][a-1] = 1;
    }
    
    DFS_by_adjacencyMatrix(adjacencyMatrix,0,visited);
}