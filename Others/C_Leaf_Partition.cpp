#include <bits/stdc++.h>
using namespace std;
vector<int> child;
void solve()
{
    int n;
    cin >> n;
    child = vector<int>(n + 1, 0);
    for (int i = 1; i < n; i++)
    {
        int p;
        cin >> p;
        child[p]++;
    }
    long long rt = 0;
    for (int i = 1; i <= n; i++)
        if (!child[i])
            rt++;
    cout << max(1LL, rt * (rt - 1)) << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}