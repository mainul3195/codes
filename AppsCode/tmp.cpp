#include <bits/stdc++.h>
using namespace std;

void solve()
{
    vector<string> v;
    string s;
    while (getline(cin, s))
        v.push_back(s);
    for (int i = 0; i < 10000; i++)
    {
        int a = rand() % v.size();
        int b = rand() % v.size();
        swap(v[a], v[b]);
    }
    for (auto i : v)
        cout << i << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    srand(time(0));
    solve();
    return 0;
}