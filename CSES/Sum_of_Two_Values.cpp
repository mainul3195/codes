#include <bits/stdc++.h>
using namespace std;
struct pr
{
    int a, b;
    bool operator<(const pr &x) const
    {
        return a < x.a;
    }
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    vector<pr> v(n);
    int index = 1;
    for (auto &[a, b] : v)
    {
        cin >> a;
        b = index++;
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
    {
        auto it = lower_bound(v.begin(), v.end(), (pr){x - v[i].a, -1});
        if (it != v.end() && (*it).a == x - v[i].a && it - v.begin() != i)
        {
            cout << v[i].b << " " << (*it).b << "\n";
            return 0;
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}