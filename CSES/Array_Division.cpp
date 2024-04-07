#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<long long> v(n);
    long long l = 0, r, mid, ans;
    for (auto &i : v)
    {
        cin >> i;
        r += i;
    }
    while (l <= r)
    {
        mid = (l + r) / 2;
        long long count = 0, tmp_sum = 0;
        for (auto i : v)
        {
            if (tmp_sum + i <= mid)
                tmp_sum += i;
            else
            {
                count++;
                tmp_sum = i;
                if (tmp_sum > mid)
                {
                    count = 2000000000;
                    break;
                }
            }
        }
        if (tmp_sum)
            count++;
        if (count <= k)
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    cout << ans << "\n";
}