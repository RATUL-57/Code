#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back
#define mp make_pair

#define Fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void BFS_by_adjacencyList(vector<vector<ll>>&adjacencyList, ll source)
{
    ll size = adjacencyList.size();

    vector<bool>visited_node(size,false);

    queue<ll>temp;

    visited_node[source] = true;

    temp.push(source);

    while(!temp.empty())
    {
        int current_index = temp.front();

        cout << current_index+1 << ' ';

        temp.pop();

        for (ll i = 0; i < adjacencyList[current_index].size(); i++) {
            ll adjacent_node = adjacencyList[current_index][i];
            if (!visited_node[adjacent_node]) {
                visited_node[adjacent_node] = true;
                temp.push(adjacent_node);
            }
        }
    }

}


void BFS_by_adjacencyMatrix(const vector<vector<int>>& adjacencyMatrix, int index) {
    int vertices = adjacencyMatrix.size();
    vector<bool> visited(vertices, false);
    queue<int> q;
    
    q.push(index);
    visited[index] = true;

    while (!q.empty()) {
        int currentVertex = q.front();
        q.pop();

        cout << currentVertex+1 << " ";

        for (int i = 0; i < vertices;i++) {
            if (adjacencyMatrix[currentVertex][i] == 1 && !visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}



int main()
{
    Fast;
    
    // ll n, m, i;
    // cin >> n >> m;

    // vector<vector<ll>>adjacencyList(n);

    // for(i=0; i<m;i++)
    // {
    //     ll a, b;
    //     cin >> a >> b;
    //     adjacencyList[a-1].pb(b-1);
    //     adjacencyList[b-1].pb(a-1);
    // }

    // BFS_by_adjacencyList(adjacencyList,0);


    int n, m;

    cin >> n >> m;

    
    vector<vector<int>>adjacencyMatrix(n,vector<int>(n,0));

    for(int i=0;i<m;i++)
    {
        int a, b;
        cin >> a >> b;
        adjacencyMatrix[a-1][b-1] = 1;
        adjacencyMatrix[b-1][a-1] = 1;
    }
    

    // Perform BFS starting from vertex 0
    cout << "BFS starting :" << endl;
    BFS_by_adjacencyMatrix(adjacencyMatrix, 0);
}

