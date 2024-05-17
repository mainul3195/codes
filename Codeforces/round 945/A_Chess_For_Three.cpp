#include<bits/stdc++.h>
using namespace std;
void solve()
{
    vector<int> v(3);
    for(auto &i: v)
        cin >> i;
    int cnt = 0;
    sort(v.rbegin(), v.rend());
    while(v[1])
    {
        cnt++;
        v[0]--;
        v[1]--;
        sort(v.rbegin(), v.rend());
    }
    if(v[0]%2)
        cout << "-1\n";
    else cout << cnt << "\n";
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