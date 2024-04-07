#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    sort(v.begin(), v.end());
    long long ans = 1;
    for (auto i : v)
    {
        if (i > ans)
        {
            cout << ans << "\n";
            return 0;
        }
        ans += i;
    }
    cout << ans << "\n";
    return 0;
}