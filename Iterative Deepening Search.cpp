#include <bits/stdc++.h>
using namespace std;
#define pb push_back
vector<int> graph[100];
vector<int> path;

bool depthLimitedSearch(int node, int goal, int limit, int parent = -1) {
    path.pb(node);
    if (node == goal)
        return true;
    if (limit == 0)
    {
        path.pop_back();
        return false;
    }
    for (int child : graph[node])
    {
        if (child != parent)
        {
            if (depthLimitedSearch(child, goal, limit - 1, node))
            {
                return true;
            }
        }
    }
    path.pop_back();
    return false;
}

bool IDS(int start, int goal, int maxDepth)
{
    for (int depth = 0; depth <= maxDepth; depth++)
    {
        path.clear();
        if (depthLimitedSearch(start, goal, depth))
        {
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int nodes, edges;
    cin >> nodes >> edges;

    for (int i = 0; i < edges; i++) {
        int u, v; cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    int start, goal, maxDepth;
    cin >> start >> goal >> maxDepth;
    cout << "The path is : ";
    if (IDS(start, goal, maxDepth))
    {
        for (int node : path)
            cout << node << " ";
    }
    else
        cout << "Path not found";

    return 0;
}
