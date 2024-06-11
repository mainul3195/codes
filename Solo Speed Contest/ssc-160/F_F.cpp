#include <bits/stdc++.h>
using namespace std;
int n, k;
string s;
bool possible(int x)
{
    string tmp = s;
    int cng = 0;
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        char c = tmp[i];
        while (i < n && (tmp[i] == c))
        {
            cnt++;
            if (cnt == x + 1)
                break;
            i++;
        }
        if (cnt == x + 1)
            if (i < n)
            {
                cng++;
                if (tmp[i] == '0')
                    tmp[i] = '1';
                else
                    tmp[i] = '0';
            }
        i--;
    }
    cout << cng << "\n";
    return cng <= k;
}
void solve()
{
    cin >> n >> k >> s;

    cout << possible(1) << "\n";
    return;


    int mx_cons = 0;
    for (int i = 0; i < s.size(); i++)
    {
        int cnt = 0;
        char c = s[i];
        while (i < s.size() && s[i] == c)
        {
            cnt++;
            i++;
        }
        i--;
        mx_cons = max(mx_cons, cnt);
    }
    int l = 1, r = mx_cons, ans = 0;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (possible(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
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