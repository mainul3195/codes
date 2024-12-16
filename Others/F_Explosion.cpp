#include <bits/stdc++.h>
using namespace std;
vector<int> degree;
int n, p, tr;
int gcd(int a, int b)
{
    if(!b)
        return a;
    return gcd(b, a%b);
}
void solve()
{
    cin >> n >> p >> tr;
    degree = vector<int>(n + 1, 0);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        degree[u]++;
        degree[v]++;
    }
    vector<int> leaf;
    for (int i = 1; i <= n; i++)
    {
        if (degree[i] == 1)
            leaf.push_back(i);
    }
    int num = n - leaf.size() - 2;
    int denum = n - 2;
    for (auto i : leaf)
    {
        if (i == p)
        {
            num++;
            break;
        }
    }
    for (auto i : leaf)
    {
        if (i == tr)
        {
            num++;
            break;
        }
    }
    cout << (num / gcd(num, denum)) << " " << (denum / gcd(num, denum)) << "\n";

    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}