#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<long long> v(n);
    for (auto &i : v)
        cin >> i;
    sort(v.begin(), v.end());
    long long last = 0;
    for (auto i : v)
    {
        long long start = i;
        long long end = last + i;
        if (start > last + 1)
        {
            cout << last + 1 << "\n";
            return;
        }
        last = end;
    }
    cout << last + 1 << "\n";

    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}