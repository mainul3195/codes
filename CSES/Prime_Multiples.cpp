#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n, k;
    cin >> n >> k;
    vector<long long> a(k);
    for (auto &i : a)
        cin >> i;
    long long ans = 0;
    for (int i = 1; i < (1 << k); i++)
    {
        vector<long long> active;
        for (int j = 0; j < k; j++)
            if (i & (1 << j))
                active.push_back(a[j]);
        long long prod = 1;
        for (auto p : active)
        {
            if (prod > n / p)
            {
                prod = n + 1;
                break;
            }
            prod *= p;
        }
        if (active.size() & 1)
            ans += n / prod;
        else
            ans -= n / prod;
    }
    cout << ans << "\n";
    return 0;
}