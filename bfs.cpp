#include<bits/stdc++.h>
using namespace std;
#define pb push_back
vector<int> graph[100];
int dist[100], parent[100];
bool vis[100];
void bfs(int source)
{
    queue<int> q;
    vis[source] = true;
    dist[source] = 0;
    parent[source] = -1;
    q.push(source);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (int i = 0; i < graph[node].size(); i++)
        {
            int next = graph[node][i];
            if (!vis[next])
            {
                vis[next] = true;
                dist[next] = dist[node] + 1;
                parent[next] = node;
                q.push(next);
            }
        }
    }

}
void printpath(int destination)
{
    vector<int>path;
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
    bfs(1);
    for (int i = 1; i <= node; i++)
        cout << "Distance from node 1 to node " << i << " is : " << dist[i] << endl;
    int destination;
    //cout << "Enter the path which you want to visit : ";
    cin >> destination;
    cout << "The path is : ";
    printpath(destination);

    return 0;
}
