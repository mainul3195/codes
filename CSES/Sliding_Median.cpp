#include <bits/stdc++.h>
using namespace std;
set<pair<int, int>> lower, upper;
void adjust()
{
    if (upper.size() > lower.size())
    {
        lower.insert(*upper.begin());
        upper.erase(upper.begin());
    }
    if (lower.size() - upper.size() > 1)
    {
        upper.insert(*lower.rbegin());
        auto it = lower.end();
        it--;
        lower.erase(it);
    }
    return;
}
void insert(int n, int ind)
{
    if (upper.size() && (*upper.begin()).first <= n)
        upper.insert({n, ind});
    else
        lower.insert({n, ind});
    adjust();
    return;
}
void delt(pair<int, int> p)
{
    if (lower.count(p))
        lower.erase(p);
    else
        upper.erase(p);
    adjust();
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v.push_back({a, i});
        insert(a, i);
        if (i < k - 1)
            continue;
        cout << (*lower.rbegin()).first << " ";
        pair<int, int> p = v[i - k + 1];
        delt(p);
    }
    return 0;
}