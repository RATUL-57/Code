#include <bits/stdc++.h>

using namespace std;

const long long N = 1e5+2;
const long long INF = 1e9+2;
vector<bool> visited(N, false);
vector<long long> distances(N, INF);
vector<pair<long long, long long>> adjacencyList[N];


void dijkstra(long long source){

    /////////////////   PRIORITY  QUEUE   ///////////////
    priority_queue<pair<long long,long long>>pq;
    pq.push({0,source});
    distances[source] = 0;

    while(!pq.empty()){
        pair<long long, long long> node = pq.top();
        
        long long cost = node.first;
        long long vertex = node.second;
        
        pq.pop();
        
        if(visited[vertex])
            continue;
        visited[vertex] = true;

        long long size = adjacencyList[vertex].size();
        for(long long i=0; i<size; i++){
            pair<long long, long long> child = adjacencyList[vertex][i];
            long long weight = child.second;
            long long child_vtx = child.first;

            if(distances[vertex] + weight < distances[child_vtx])
            {
                distances[child_vtx] = distances[vertex] + weight;
                pq.push({distances[child_vtx], child_vtx});
            }
        }
    }

    ///////////////    SET    /////////////////////
    // set<pair<long long,long long>>st;

    // st.insert({0,source});
    // distances[source] = 0;

    // while(st.size() > 0)
    // {
    //     auto node = *st.begin();
    //     long long cost = node.first;
    //     long long vertex = node.second;

    //     st.erase(st.begin());

    //     if(visited[vertex])
    //         continue;
    //     visited[vertex] = true;

    //     for(auto child : adjacencyList[vertex])
    //     {
    //         long long child_vtx = child.first;
    //         long long weight = child.second;

    //         if(distances[vertex] + weight < distances[child_vtx])
    //         {
    //             distances[child_vtx] = distances[vertex] + weight;
    //             st.insert({distances[child_vtx], child_vtx});
    //         }
    //     }
    // }
}

int main()
{
    long long n, m;
    cin >> n >> m;
    for(long long i=0;i<m;i++)
    {
        long long a, b, cost;
        cin >> a >> b >> cost;
        adjacencyList[a].push_back({b,cost});
    }

    dijkstra(1);

    for(long long i=1;i<=n;i++)
        cout << distances[i] << ' ';
}