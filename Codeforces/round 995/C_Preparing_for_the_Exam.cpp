#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> lists(m);
    for (auto &i : lists)
        cin >> i;
    vector<int> pare(k);
    for (auto &i : pare)
        cin >> i;
    if (k == n)
    {
        for (int i = 0; i < m; i++)
            cout << "1";
        cout << "\n";
        return;
    }
    if (k < n - 1)
    {
        for (int i = 0; i < m; i++)
            cout << "0";
        cout << "\n";
        return;
    }
    int nai = k + 1, cnt = 1;
    for (auto i : pare)
    {
        if (cnt != i)
        {
            nai = cnt;
            break;
        }
        cnt++;
    }
    // for (auto i : pare)
    //     cout << i << " ";
    // cout << "\n";
    // cout << nai << "\n";
    for (auto i : lists)
    {
        if (i == nai)
            cout << "1";
        else
            cout << "0";
    }
    cout << "\n";
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