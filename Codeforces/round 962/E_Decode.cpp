#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    vector<long long> prev(3 * n, 0);
    int x = 3 * n / 2;
    int sft = 0;
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        int ind;
        if (s[i] == '0')
            sft--, ind = -1;
        else
            sft++, ind = 1;
        prev[x + ind - sft] += i + 1;
        ans = (ans + prev[x - sft] * (n - i) % mod) % mod;
    }
    cout << ans << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}