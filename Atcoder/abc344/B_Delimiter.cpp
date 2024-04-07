#include <bits/stdc++.h>
using namespace std;

void solve()
{
    vector<int> v;
    int n;
    while (cin >> n)
    {
        v.push_back(n);
    }
    reverse(v.begin(), v.end());
    for (auto i : v)
        cout << i << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}