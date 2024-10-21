#include <bits/stdc++.h>
using namespace std;
struct nd
{
    int id;
    long long l, r, m;
    long long ans;
    nd()
    {
        id = l = r = m = ans = 0;
    }
};
vector<nd> q;
int t;
void okdone(int k, int i = 0, int prev = 1, long long num = 0)
{
    if (i == k)
    {
        for (auto &[_, l, r, m, a] : q)
        {
            if (l > num)
                break;
            if ((num >= l) && (num <= r) && (num % m == 0))
            {
                a++;
                // if (_ == 2)
                //     cout << num << "\n";
            }
        }
        return;
    }
    if (i <= k / 2)
    {
        int j = prev;
        if ((i == k / 2 )&& i)
            j++;
        for (; j <= 9; j++)
            okdone(k, i + 1, j, num * 10 + j);
    }
    else
    {
        int j = prev;
        if (i == k / 2+1)
            j--;
        for (; j > 0; j--)
            okdone(k, i + 1, j, num * 10 + j);
    }
    return;
}
bool cmp1(nd &a, nd &b)
{
    return a.l < b.l;
}
bool cmp2(nd &a, nd &b)
{
    return a.id < b.id;
}
void solve()
{
    cin >> t;
    q = vector<nd>(t);
    for (int i = 0; i < t; i++)
    {
        q[i].id = i;
        cin >> q[i].l >> q[i].r >> q[i].m;
    }
    sort(q.begin(), q.end(), cmp1);
    for (int k = 1; k <= 17; k += 2)
        okdone(k);
    sort(q.begin(), q.end(), cmp2);
    for (auto [i, l, r, m, a] : q)
        cout << "Case #" << i + 1 << ": " << a << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    solve();
    return 0;
}