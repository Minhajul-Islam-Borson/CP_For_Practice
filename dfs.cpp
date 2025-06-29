#include <bits/stdc++.h>
using namespace std;

#define pb push_back
vector<int> graph[100];
int dist[100], parent[100];
bool vis[100];

void dfs(int node, int d = 0, int par = -1)
{
    vis[node] = true;
    dist[node] = d;
    parent[node] = par;

    for (int i = 0; i < graph[node].size(); i++)
    {
        int next = graph[node][i];
        if (!vis[next])
        {
            dfs(next, d + 1, node);
        }
    }
}

void printpath(int destination)
{
    vector<int> path;
    while (destination != -1)
    {
        path.pb(destination);
        destination = parent[destination];
    }
    reverse(path.begin(), path.end());
    for (auto i : path)
        cout << i << " ";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int node, edge;
    cin >> node >> edge;
    while (edge--)
    {
        int u, v;
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    dfs(1);

    for (int i = 1; i <= node; i++)
        cout << "Distance from node 1 to node " << i << " is : " << dist[i] << endl;

    int destination;
    cin >> destination;
    cout << "The path is : ";
    printpath(destination);

    return 0;
}
