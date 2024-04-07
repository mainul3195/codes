#include <bits/stdc++.h>
using namespace std;
set<pair<int, int>> lower, upper;
long long lower_sum = 0, upper_sum = 0;
void adjust()
{
    if (lower.size() < upper.size())
    {
        auto it = upper.begin();
        lower.insert(*it);
        lower_sum += (*it).first;
        upper_sum -= (*it).first;
        upper.erase(it);
    }
    else if (lower.size() - upper.size() > 1)
    {
        auto it = lower.end();
        it--;
        upper.insert(*it);
        lower_sum -= (*it).first;
        upper_sum += (*it).first;
        lower.erase(it);
    }
    return;
}
void insert(pair<int, int> p)
{
    if (lower.size() && (*lower.rbegin()).first >= p.first)
    {
        lower.insert(p);
        lower_sum += p.first;
    }
    else
    {
        upper.insert(p);
        upper_sum += p.first;
    }
    adjust();
    return;
}
void dlt(pair<int, int> p)
{
    if (lower.count(p))
    {
        lower_sum -= p.first;
        lower.erase(p);
    }
    else
    {
        upper_sum -= p.first;
        upper.erase(p);
    }
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
        insert({a, i});
        if (i < k - 1)
            continue;
        long long mid = (*lower.rbegin()).first;
        cout << lower.size() * mid - lower_sum + upper_sum - upper.size() * mid << " ";
        dlt(v[i - k + 1]);
    }
    return 0;
}