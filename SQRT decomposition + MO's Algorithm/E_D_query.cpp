#include<bits/stdc++.h>
using namespace std;
struct nd{
    int l, r, ind;
};
int n, m;
bool cmp(const nd &a, const nd &b)
void solve()
{
    cin >> n;
    m = sqrt(n+.5);
    vector<int> v(n+1);
    for(int i = 1; i<=n; i++)
        cin >> v[i];
    int q;
    cin >> q;
    vector<nd> queries;
    for(int i = 0; i<q; i++)
    {
        int l, r;
        cin >> l >> r;
        queries.push_back({l, r, i+1});
    }
    sort(queries.begin(), queries.end(), cmp);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}