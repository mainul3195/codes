#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int>v(n);
    for(auto &i: v)
        cin >> i;
    reverse(v.begin(), v.end());
    for(int i = n-1; i>=0; i--)
    {
        int cur_pos = n-i;
        int ind = lower_bound(v.begin(), v.end(), cur_pos)-v.begin()+1;;
        if(ind != n-v[i]+1)
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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