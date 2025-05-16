#include<bits/stdc++.h>
using namespace std;
int n;
vector<string> rotate(vector<string> v)
{
    vector<string> ans= v;
    for(int i = 0; i<n; i++)
        for(int j = 0; j<n; j++)
            ans[j][n-1-i] = v[i][j];
    return ans;
}
int dif(vector<string> a, vector<string> b)
{
    int cnt = 0;
    for(int i = 0; i<n; i++)
        for(int j = 0; j<n; j++)
            if(a[i][j]!=b[i][j])
                cnt++;
    return cnt;
}
void solve()
{
    cin >> n;
    vector<string> s(n), t(n);
    for(auto &c: s)
        cin >> c;
    for(auto &c: t)
        cin >> c;
    int ans = dif(s, t);
    s = rotate(s);
    ans = min(ans, dif(s, t)+1);
    s = rotate(s);
    ans = min(ans, dif(s, t)+2);
    s = rotate(s);
    ans = min(ans, dif(s, t)+3);
    cout << ans << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}