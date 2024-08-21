#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    while (s.back() != '.' && s.back() == '0')
        s.pop_back();
    if (s.back() == '.')
        s.push_back('0');
    reverse(s.begin(), s.end());
    while (s.back() != '.' && s.back() == '0')
        s.pop_back();
    if (s.back() == '.')
        s.pop_back();
    cout << s << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}