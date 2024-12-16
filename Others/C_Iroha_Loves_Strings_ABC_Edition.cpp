#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, l;
    cin >> n >> l;
    vector<string> s(n);
    for (auto &i : s)
        cin >> i;
    sort(s.begin(), s.end());
    for (auto i : s)
        cout << i;
    cout << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}