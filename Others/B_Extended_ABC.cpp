#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    set<char> st;
    char prev = 'A';
    for (auto c : s)
    {
        if (c < prev)
        {
            cout << "No\n";
            return;
        }
        prev = c;
    }
    if (prev > 'C')
    {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}