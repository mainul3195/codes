#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>>v(2*n+2);
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<=i; j++)
        {
            int x;
            cin >> x;
            v[i].push_back(x);
        }
    }
    for(int i = n; i<2*n-1; i++)
    {
        for(int j = 0; j<=2*n-i - 2; j++)
        {
            int x;
            cin >> x;
            v[i].push_back(x);
        }
    }
    for(int i = 0; i<2*n-1; i++)
    {
        for(auto el: v[i])
            cout << el << " ";
        cout << "\n";
    }
    cout << "\n\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    int tc = 0;
    while(t--)
    {
        cout << "Case " << ++tc << ": ";
        solve();
    }
    return 0;
}