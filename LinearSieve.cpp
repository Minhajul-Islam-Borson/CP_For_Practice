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
	int N = 1e7 + 10;
	vector<bool> isPrime(N, true);
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i < N; i++)
	{
		if (isPrime[i] == true)
		{
			for (int j = 2 * i; j < N; j += i)
			{
				isPrime[j] = false;
			}
		}
	}

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		if (isPrime[n])
			cout << "Prime" << endl;
		else cout << "Not Prime" << endl;
	}



	return 0;
}