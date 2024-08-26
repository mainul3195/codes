#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.first > b.first || (a.first == b.first && a.second > b.second);
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> v;
    long long sm = 0;
    vector<pair<int, int>> pr;
    set<int> strt;
    vector<int> multi;
    for (int i = 0; i < n; i++)
    {
        v.clear();
        int l;
        cin >> l;
        while (l--)
        {
            int x;
            cin >> x;
            v.push_back(x);
        }
        sort(v.rbegin(), v.rend());
        // for (auto j : v)
        //     cout << j << " ";
        // cout << "\n";
        vector<int> tmp;
        int cur = 0;
        while (tmp.size() < 2)
        {
            if (v.size() == 0)
            {
                tmp.push_back(cur);
                cur++;
            }
            else if (v.back() == cur)
            {
                while (v.size() && v.back() == cur)
                    v.pop_back();
                cur++;
            }
            else
            {
                tmp.push_back(cur);
                cur++;
            }
        }
        // for (auto j : tmp)
        //     cout << j << " ";
        // cout << "\n";
        sm = max(sm, (long long)tmp.back());
        pr.push_back({tmp[0], tmp[1]});
        if (strt.find(tmp[0]) == strt.end())
            strt.insert(tmp[0]);
        else
            multi.push_back(tmp[0]);
    }

    sort(pr.begin(), pr.end(), cmp);
    map<int, int> last;
    for (auto [a, b] : pr)
    {
        int tmp;
        if (last.find(b) == last.end())
            tmp = b;
        else
            tmp = last[b];
        if (last.find(a) == last.end())
            last[a] = tmp;
        else
            last[a] = max(last[a], tmp);
    }
    sort(multi.begin(), multi.end());
    vector<int> val_mul(multi.size());
    for (int i = 0; i < val_mul.size(); i++)
        val_mul[i] = last[multi[i]];
    int mx = 0;
    for(int i = 0; )
    // cout << m << " " << sm << "\n";
    if (m <= sm)
        cout << sm * (m + 1) << "\n";
    else
    {
        long long last = m - sm;
        cout << sm * (sm + 1) + sm * last + (last + 1) * last / 2 << "\n";
    }
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