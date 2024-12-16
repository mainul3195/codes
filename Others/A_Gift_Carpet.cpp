#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string>v(n);
    for(auto &s: v)
        cin >> s;
    bool ok = 0;
    string target = "vika";
    int ind = 0;
    for(int col = 0; ind<4 && col<m; col++)
    {
        for(int i = 0; i<n; i++)
        {
            if(v[i][col]==target[ind])
            {
                ind++;
                break;
            }
        }
    }
    if(ind == 4)
    {
        cout << "YES\n";
    }
    else cout << "NO\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}