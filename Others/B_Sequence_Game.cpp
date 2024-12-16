#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int>v(n);
    for(auto &i: v)
        cin >> i;
    vector<int> ans;
    ans.push_back(v[0]);
    for(int i = 1; i<n; i++)
    {
        if(v[i]<ans.back())
            ans.push_back(v[i]);
            ans.push_back(v[i]);
    }
    cout << ans.size() << "\n";
    for(auto i: ans)
        cout << i << " ";
        cout << "\n";
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