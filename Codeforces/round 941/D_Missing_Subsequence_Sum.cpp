#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    int lg = log2(n + .5);
    vector<int> v;
    int mul = 1;
    for (int i = 0; i <= lg; i++)
    {
        v.push_back(mul);
        mul <<= 1;
    }
    int lr = log2(k + .4);
    v.erase(find(v.begin(), v.end(), 1 << lr));
    v.push_back(k + 1);
    v.push_back(k - 1 - ((1 << lr) - 1));
    v.push_back((1 << (lr + 1)) + k);
    cout << v.size() << "\n";
    for (auto i : v)
        cout << i << " ";
    cout << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}