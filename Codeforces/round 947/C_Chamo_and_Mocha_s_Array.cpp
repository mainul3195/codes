#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &i: v)
        cin >> i;
    if(n==2)
        cout << min(v[0], v[1]) << "\n";
    else
    {
        int mx = -1;
        for(int i = 2; i<n; i++)
        {
            vector<int> emni;
            emni.push_back(v[i]);
            emni.push_back(v[i-1]);
            emni.push_back(v[i-2]);
            sort(emni.begin(), emni.end());
            mx = max(mx, emni[1]);
        }
        cout << mx << "\n";
    }
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