#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int>v(n);
    int xr = 0;
    for(auto &i: v)
    {
        cin >> i;
        xr ^= i;
    }
    if(n%4 == 1)
        xr ^= 1;
    set<int> st;
    for(auto i: v)
        st.insert(i^xr);
    if(st.size() == n)
        cout << "YES\n";
    else cout << "NO\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve(); 
    return 0;
}