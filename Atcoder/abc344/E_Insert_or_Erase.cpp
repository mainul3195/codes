#include <bits/stdc++.h>
using namespace std;
#define inf 2000000000
vector<int> v;

void solve()
{
    int n;
    cin >> n;
    map<int, int> par, child;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    par[v[0]] = 0;
    child[0] = v[0];
    par[inf] = v[n-1];
    child[v[n-1]] = inf;
    for (int i = 1; i < n; i++)
        par[v[i]] = v[i - 1], child[v[i - 1]] = v[i];
    int q;
    cin >> q;
    while(q--)
    {
        int t;
        cin >> t;
        if(t==2)
        {
            int x;
            cin >> x;
            child[par[x]] = child[x];
            par[child[x]] = par[x];
            child.erase(child.find(x));
            par.erase(par.find(x));
        }
        else
        {
            int a, b;
            cin >> a >> b;
            int c = child[a];
            child[a] = b;
            par[b] = a;
            child[b] = c;
            par[c] = b;
        }
    }
    int cur = child[0];
    while(cur != inf)
    {
        cout << cur << " \n"[child[cur]==inf];
        cur = child[cur];
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}