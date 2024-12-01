#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18 + 5;
const int intinf = 1e9 + 7;
#define pb push_back
#define pob pop_back
#define ll long long
#define endl "\n"
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define M_PI 3.14159265358979323846
#define max_index 100005

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> nim(n);
    for (int i = 0; i < n; i++)
        cin >> nim[i];
    int nim_sum = 0;
    for (int i = 0 ; i < n; i++)
    {
        nim_sum ^= nim[i];
    }
    cout << nim_sum << endl;
    if (nim_sum == 0)
        cout << "2nd palyer is win" << endl;
    else cout << "1st player is win" << endl;


    return 0;
}