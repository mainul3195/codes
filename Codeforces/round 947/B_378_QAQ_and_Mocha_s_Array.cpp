#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &i: v)
        cin >> i;
    sort(v.begin(), v.end());
    int mn = v[0];
    int s_mn = -1;
    for(int i = 1; i<n; i++)
        if(v[i]%mn)
        {
            s_mn = v[i];
            break;
        }
    bool ok = 1;
    for(int i = 0; i<n; i++)
    {
        if(!((v[i]%mn ==0) || ((s_mn != -1) && (v[i]%s_mn==0))))
        {
            ok = 0;
            break;
        }
    }
    if(ok)
        cout << "Yes\n";
    else cout << "No\n";
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