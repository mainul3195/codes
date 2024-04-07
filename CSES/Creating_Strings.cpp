#include <bits/stdc++.h>
using namespace std;
void solve()
{
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    vector<string> v;
    v.push_back(s);
    while (next_permutation(s.begin(), s.end()))
        v.push_back(s);
    cout << v.size() << "\n";
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