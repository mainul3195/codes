#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int p, l;
    cin >> p >> l;
    int n = p - l;
    vector<int> div;
    for (long long i = 1; i * i <= n; i++)
        if (n % i == 0)
        {
            div.push_back(i);
            if (i != n / i)
                div.push_back(n / i);
        }
    sort(div.rbegin(), div.rend());
    while (div.size() && div.back() <= l)
        div.pop_back();
    if (div.empty())
        cout << "impossible\n";
    else
    {
        while (div.size())
        {
            cout << div.back() << " ";
            div.pop_back();
        }
        cout << "\n";
    }

    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, tc = 0;
    cin >> t;
    while (t--)
    {
        cout << "Case " << ++tc << ": ";
        solve();
    }
    return 0;
}