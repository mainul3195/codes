#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int n;
	cin >> n;
	int xr = 0;
	for(int i = 0; i<n; i++)
	{
		int x;
		cin >> x;
		xr ^= x;
	}
	if(xr)
		cout << "first\n";
	else cout << "second\n";
	return;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}