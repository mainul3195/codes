#include <bits/stdc++.h>
using namespace std;
#define mod 1000003
long long forw = 0, lft = 0, rght = 0;
struct nd
{
    long long l, r, f;
    nd operator+(nd a)
    {
        a.l = (a.l + l) % mod;
        a.r = (a.r + r) % mod;
        a.f = (a.f + f) % mod;
        return a;
    }
};
nd solve_repeat()
{
    int n;
    cin >> n;
    string tmp;
    cin >> tmp;
    nd node = {0, 0, 0};
    while (cin >> tmp && tmp != "]")
    {
        if (tmp == "forward")
        {
            long long x;
            cin >> x;
            node.f += x % mod;
            node.f %= mod;
        }
        else if (tmp == "left")
        {
            long long x;
            cin >> x;
            node.l += x % mod;
            node.l %= mod;
        }
        else if (tmp == "right")
        {
            long long x;
            cin >> x;
            node.r += x % mod;
            node.r %= mod;
        }
        else if (tmp == "repeat")
            node = node + solve_repeat();
    }
    node.f = (node.f * n) % mod;
    node.l = (node.l * n) % mod;
    node.r = (node.r * n) % mod;
    return node;
}
void solve()
{
    string s;
    cin >> s;
    nd node = {0, 0, 0};
    while (cin >> s && s != "end")
    {
        if (s == "repeat")
            node = node + solve_repeat();
        else
        {
            if (s == "forward")
            {
                long long x;
                cin >> x;
                node.f += x % mod;
                node.f %= mod;
            }
            else if (s == "left")
            {
                long long x;
                cin >> x;
                node.l += x % mod;
                node.l %= mod;
            }
            else if (s == "right")
            {
                long long x;
                cin >> x;
                node.r += x % mod;
                node.r %= mod;
            }
        }
    }
    cout << node.l << " " << node.r << " " << node.f << "\n";
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