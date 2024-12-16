#include <bits/stdc++.h>
using namespace std;
map<char, char> mp;
void solve()
{
    long long n;
    cin >> n;
    string s = "";
    while (n)
    {
        s.push_back(n % 9 + '0');
        n /= 9;
    }
    reverse(s.begin(), s.end());
    for (auto c : s)
        cout << mp[c];
    cout << "\n";
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    mp['0'] = '0';
    mp['1'] = '1';
    mp['2'] = '2';
    mp['3'] = '3';
    mp['4'] = '5';
    mp['5'] = '6';
    mp['6'] = '7';
    mp['7'] = '8';
    mp['8'] = '9';
    while (t--)
        solve();
    return 0;
}