#include <bits/stdc++.h>
using namespace std;
#define pb push_back

vector<int> graph[100];
bool found = false;
vector<int> path;

bool DLS(int node, int goal, int limit, int parent = -1)
{
    path.pb(node);
    if (node == goal)
    {
        return true;
    }
    if (limit == 0)
    {
        path.pop_back();
        return false;
    }
    for (int child : graph[node])
    {
        if (child != parent)
        {
            if (DLS(child, goal, limit - 1, node))
            {
                return true;
            }
        }
    }

    path.pop_back();
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int nodes, edges;
    cout << "Enter number of nodes and edges: ";
    cin >> nodes >> edges;
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    int start, goal, depth_limit;
    cout << "Enter source node: ";
    cin >> start;
    cout << "Enter goal node: ";
    cin >> goal;
    cout << "Enter depth limit: ";
    cin >> depth_limit;
    if (DLS(start, goal, depth_limit))
    {
        cout << "Goal node found!" << endl;
        cout << "Path: ";
        for (int node : path)
            cout << node << " ";
        cout << endl;
    }
    else
        cout << "Goal not found within depth limit." << endl;

    return 0;
}
