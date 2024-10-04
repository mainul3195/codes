#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    int mn = 2000000000;
    for (auto i : v)
        mn = min(mn, i);
    set<int> st;
    for (auto i : v)
    {
        for (int d = 1; d * d <= i; d++)
        {
            if (i % d == 0)
                st.insert(d), st.insert(i / d);
        }
    }
    vector<int> vv;
    for (auto i : st)
    {
        if (i <= mn)
            vv.push_back(i);
        else
            break;
    }
    // for (auto i : vv)
    //     cout << i << " ";
    // cout << "\n";
    int cnt = 0;
    for (auto i : vv)
    {
        int g = 0;
        for (auto j : v)
        {
            if (g == 0)
            {
                if (j % i == 0)
                    g = j;
                continue;
            }
            if (j % i == 0)
                if (__gcd(g, j) >= i)
                    g = __gcd(g, j);
        }
        if (g == i)
        {
            cnt++;
            // cout << i << "..\n";
        }
        // if (i == 4)
        //     cout << g << "\n";
    }
    cout << cnt << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}