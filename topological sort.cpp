#include<bits/stdc++.h>
using namespace std;
//#define ll long long
#define mx 100001
vector<int>graph[mx];
vector<int>indegree(mx, 0), result;
queue<int> q;

void top_sort(int node)
{
    for (int i = 1; i <= node; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    while (!q.empty())
    {
        int n = q.front();
        q.pop();
        result.push_back(n);
        for (int v : graph[n])
        {
            indegree[v]--;
            if (indegree[v] == 0)
                q.push(v);
        }
    }
    if (result.size() != node)
        cout << "IMPOSSIBLE";
    else
    {
        for (auto i : result)
            cout << i << " ";
    }
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
    for (int i = 0; i < edge; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        indegree[v]++;
    }


    top_sort(node);

    return 0;
}
