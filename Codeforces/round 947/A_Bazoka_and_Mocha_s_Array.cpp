#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &i: v)
        cin >> i;
    for(int i = 0; i<=n; i++)
    {
        if(is_sorted(v.begin(), v.end()))
        {
            cout << "Yes\n";
            return;
        }
        rotate(v.begin(), v.begin()+1, v.end());
    }
    cout << "No\n";
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