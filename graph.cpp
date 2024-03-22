#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back
#define mp make_pair

#define Fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);

class graph
{
private:
    ll vertex_number;
    ll edge_number;
    const ll INF = LLONG_MAX;
    vector<vector<ll>> adjacencyMatrix;
    vector<vector<ll>> adjacency_list;
    vector<vector<pair<ll, ll>>> adjacencyList;
    vector<bool> visited;
    vector<ll> distances;
    vector<vector<ll>> all_distance;
    vector<ll> parent;

public:
    graph() : vertex_number(0), edge_number(0), adjacency_list(0), adjacencyList(0), adjacencyMatrix(0, vector<ll>(0, 0)), visited(0, false), parent(0, -1), distances(0, INF) {}
    graph(ll a, ll b) : vertex_number(a), edge_number(b), adjacency_list(a), adjacencyList(a), adjacencyMatrix(a, vector<ll>(a, 0)), visited(a, false), distances(a, INF), parent(a, -1), all_distance(a, vector<ll>(a, INF)) {}

    void print_distance();
    void print_all_distance();
    void print_parent();

    void initialize_adjacency_matrix();
    void initialize_adjacency_list();
    void initialize_adjacency_matrix_with_cost();
    void initialize_adjacency_list_with_cost();

    void BFS_by_adjacencyList(ll index);
    void BFS_by_adjacencyMatrix(ll index);
    void DFS_by_adjacencyList(ll source);
    void DFS_by_adjacencyMatrix(ll source);

    void dijkstra(ll source);
    void bellman_ford_by_adjacency_matrix(ll source);
    void bellman_ford_by_adjacency_list(ll source);
    void floyd_warshall();
};

int main()
{
    Fast;

    ll n, m;
    cin >> n >> m;
    graph gp(n, m);

    // gp.initialize_adjacency_list();
    // gp.initialize_adjacency_matrix();
    // gp.DFS_by_adjacencyList(1);
    // gp.DFS_by_adjacencyMatrix(1);

    gp.initialize_adjacency_list_with_cost();
    // gp.dijkstra(1);
    // gp.print_distance();

    // gp.initialize_adjacency_matrix_with_cost();
    //  gp.floyd_warshall();
    //  gp.print_all_distance();

    // gp.bellman_ford(1);
    gp.bellman_ford_by_adjacency_list(0);
    // gp.print_distance();
}

void graph::initialize_adjacency_matrix()
{
    for (ll i = 0; i < edge_number; i++)
    {
        ll a, b;
        cin >> a >> b;
        adjacencyMatrix[a - 1][b - 1] = 1;
        adjacencyMatrix[b - 1][a - 1] = 1;
    }
}

void graph::initialize_adjacency_matrix_with_cost()
{
    for (ll i = 0; i < edge_number; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        adjacencyMatrix[a - 1][b - 1] = c;
        adjacencyMatrix[b - 1][a - 1] = c;
    }
}

void graph::initialize_adjacency_list()
{
    for (ll i = 0; i < edge_number; i++)
    {
        ll a, b;
        cin >> a >> b;
        adjacency_list[a].push_back(b);
        adjacency_list[b].push_back(a);
    }
}

void graph::initialize_adjacency_list_with_cost()
{
    for (ll i = 0; i < edge_number; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        adjacencyList[a].push_back({b, c});
        adjacencyList[b].push_back({a, c});
    }
}

void graph::BFS_by_adjacencyMatrix(ll index)
{

    vector<bool> visited(vertex_number, false);
    queue<int> q;

    q.push(index);
    visited[index] = true;

    while (!q.empty())
    {
        ll currentVertex = q.front();
        q.pop();

        cout << currentVertex + 1 << " ";

        for (ll i = 0; i < vertex_number; i++)
        {
            if (adjacencyMatrix[currentVertex][i] == 1 && !visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

void graph::BFS_by_adjacencyList(ll source)
{
    vector<bool> visited_node(vertex_number, false);

    queue<ll> temp;

    visited_node[source] = true;

    temp.push(source);

    while (!temp.empty())
    {
        ll current_index = temp.front();

        cout << current_index + 1 << ' ';

        temp.pop();

        for (ll i = 0; i < adjacency_list[current_index].size(); i++)
        {
            ll adjacent_node = adjacency_list[current_index][i];
            if (!visited_node[adjacent_node])
            {
                visited_node[adjacent_node] = true;
                temp.push(adjacent_node);
            }
        }
    }
}

void graph::DFS_by_adjacencyMatrix(ll index)
{
    visited[index] = true;
    cout << index + 1 << " ";

    for (ll i = 0; i < adjacencyMatrix[index].size(); ++i)
    {
        if (!visited[i] && adjacencyMatrix[index][i] != 0)
            DFS_by_adjacencyMatrix(i);
    }
}

void graph::DFS_by_adjacencyList(ll index)
{
    visited[index] = true;
    cout << index + 1 << " ";

    for (ll i = 0; i < adjacency_list[index].size(); ++i)
    {
        if (!visited[adjacency_list[index][i]])
            DFS_by_adjacencyList(adjacency_list[index][i]);
    }
}

void graph::print_distance()
{
    for (ll i = 0; i < vertex_number; i++)
    {
        cout << distances[i] << ' ';
    }
    cout << endl;
}

void graph::print_all_distance()
{
    for (ll i = 0; i < vertex_number; i++)
    {
        for (ll j = 0; j < vertex_number; j++)
        {
            cout << all_distance[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

void graph::print_parent()
{
    for (ll i = 0; i < vertex_number; i++)
    {
        cout << parent[i] << ' ';
    }
    cout << endl;
}

void graph::dijkstra(ll source)
{

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, source});
    distances[source] = 0;

    while (!pq.empty())
    {
        pair<ll, ll> node = pq.top();

        ll cost = node.first;
        ll vertex = node.second;

        pq.pop();

        if (visited[vertex])
            continue;
        visited[vertex] = true;

        ll size = adjacencyList[vertex].size();
        for (ll i = 0; i < size; i++)
        {
            pair<ll, ll> child = adjacencyList[vertex][i];
            ll weight = child.second;
            ll child_vtx = child.first;

            if (distances[vertex] + weight < distances[child_vtx])
            {
                distances[child_vtx] = distances[vertex] + weight;
                pq.push({distances[child_vtx], child_vtx});
                parent[child_vtx] = vertex;
            }
        }
    }
}

void graph::floyd_warshall()
{
    for (ll i = 0; i < vertex_number; i++)
    {
        for (ll j = 0; j < vertex_number; j++)
        {
            if (i == j)
            {
                adjacencyMatrix[i][j] = 0;
            }
            else if (adjacencyMatrix[i][j] == 0)
            {
                adjacencyMatrix[i][j] = INF;
            }
        }
    }

    for (ll i = 0; i < vertex_number; i++)
    {
        for (ll j = 0; j < vertex_number; j++)
        {
            all_distance[i][j] = adjacencyMatrix[i][j];
        }
    }

    for (ll k = 0; k < vertex_number; ++k)
    {
        for (ll i = 0; i < vertex_number; ++i)
        {
            for (ll j = 0; j < vertex_number; ++j)
            {
                if (all_distance[i][k] != INF && all_distance[k][j] != INF && all_distance[i][k] + all_distance[k][j] < all_distance[i][j])
                {
                    all_distance[i][j] = all_distance[i][k] + all_distance[k][j];
                }
            }
        }
    }

    // for (ll i = 0, k = vertex_number; i < vertex_number; ++i)
    // {
    //     for (ll j = 0; j < vertex_number; ++j)
    //     {
    //         if (all_distance[i][k] + all_distance[k][j] < all_distance[i][j])
    //         {
    //             cout << "Negetive cycle detected at path between " << i << " and " << j << endl;
    //         }
    //     }
    // }
}

void graph::bellman_ford_by_adjacency_matrix(ll source)
{
    distances[source] = 0;

    for (ll i = 0; i < vertex_number - 1; i++)
    {
        for (ll j = 0; j < vertex_number; j++)
        {
            for (ll k = 0; k < vertex_number; k++)
            {
                if (adjacencyMatrix[j][k] != 0 && distances[j] != INF && distances[j] + adjacencyMatrix[j][k] < distances[k])
                {
                    distances[k] = distances[j] + adjacencyMatrix[j][k];
                }
            }
        }
    }

    for (ll j = 0; j < vertex_number; j++)
    {
        for (ll k = 0; k < vertex_number; k++)
        {
            if (adjacencyMatrix[j][k] != 0 && distances[j] != INF && distances[j] + adjacencyMatrix[j][k] < distances[k])
            {
                cout << "Negetive cycle detected at " << j << " and " << k << endl;
            }
        }
    }
}

void graph::bellman_ford_by_adjacency_list(ll source)
{
    distances[source] = 0;

    for (ll i = 0; i < vertex_number - 1; i++)
    {
        for (ll j = 0; j < vertex_number; j++)
        {
            for (auto neighbor : adjacencyList[j])
            {
                int v = neighbor.first;
                int weight = neighbor.second;
                if (distances[j] != LLONG_MAX && distances[j] + weight < distances[v])
                {
                    distances[v] = distances[j] + weight;
                }
            }
        }
    }

    for (ll j = 0; j < vertex_number; j++)
    {
        for (auto neighbor : adjacencyList[j])
        {
            int v = neighbor.first;
            int weight = neighbor.second;
            if (distances[j] + weight < distances[v])
            {
                cout << "Negetive cycle at " << j << " and " << v << endl;
            }
        }
    }
}