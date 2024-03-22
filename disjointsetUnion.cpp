// In The Name Of ALlah, The most Gracious The Most Merciful
#include <bits/stdc++.h>
#define ll long long
#define shoot                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define tc \
    int t; \
    cin >> t;
#define vi vector<int>
#define pp pair<int, int>
#define cy cout << "YES" \
                << "\n"
#define cn cout << "NO" \
                << "\n"
using namespace std;

class DisJointSetUnion
{
    vector<int> rank;
    vector<int> parent;
    vector<int>size;

public:
    DisJointSetUnion(int n)
    {
        rank.resize(n + 1, 0);
        size.resize(n+1,1);
        parent.resize(n + 1);

        for (int i = 1; i < n + 1; i++)
        {
            parent[i] = i;
        }
    }

    int FindParent(int node)
    {
        if (node == parent[node])
            return node;

        return parent[node] = FindParent(parent[node]);
    }

    void UnionByRank(int a, int b)
    {
        int x = FindParent(a), y = FindParent(b);
        if (x == y)
        {
            return;
        }
        if (rank[x] < rank[y])
        {
            parent[x] = y;
        }
        else if (rank[x] > rank[y])
        {
            parent[y] = x;
        }else{
            parent[y] = x;
            rank[x]++;
        }
    }

    void UnionBySize(int a, int b){
          int x = FindParent(a), y = FindParent(b);
        if (x == y)
        {
            return;
        }

        if(size[x]>size[y]){
            parent[y]=x;
            size[x]+=size[y]; 
        }else if(size[x]<size[y]){
            parent[x]=y;
            size[y]+=size[x];
         
        }else{
            parent[x]=y;
            size[y]+=size[x]; 
        }
    }
};
int main()
{
    shoot;
    int n;
    DisJointSetUnion ds(8);
    ds.UnionByRank(1,2);
    ds.UnionByRank(2,8);
    ds.UnionByRank(4,2);
    ds.UnionByRank(5,7);

    cout<<ds.FindParent(8)<<endl;

    return 0;
}