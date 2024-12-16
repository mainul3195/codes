#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<long long> v, cs;
long long find_sum(int i, int j)
{
    if (i > j)
        return 0;
    if (!i)
        return cs[j];
    return cs[j] - cs[i - 1];
}
int bruteforce()
{
    int ans = 0, l, r;
    for (int i = 0; i < 10; i++)
        for (int j = i + 1; j < 10; j++)
        {
            int mx = 0;
            for (int k = i + 1; k < j; k++)
                mx = max(mx, v[k]);
            if (mx < min(v[i], v[j]))
            {
                int tot = min(v[i], v[j]) * (j - i - 1);
                for (int k = i + 1; k < j; k++)
                    tot -= v[k];
                if (tot > ans)
                {
                    ans = tot;
                    l = i, r = j;
                }
            }
        }
    cout << l << " -> " << r << "\n";
    return ans;
}
void solve()
{
    int n = 10;
    cin >> n;
    v = cs = vector<long long>(n, 0);
    // while (1)
    {
        for (auto &i : v)
            cin >> i;
        // for (int i = 0; i < 10; i++)
        //     v[i] = rand() % 10 + 1;
        cs[0] = v[0];
        for (int i = 1; i < n; i++)
            cs[i] = cs[i - 1] + v[i];
        vector<long long> index, height;
        int prev = v[0];
        long long ans = 0;
        v.push_back(0);
        for (int i = 1; i <= n; i++)
        {
            if (v[i] <= prev)
            {

                while (index.size())
                {
                    int ind = index.back();
                    long long h = height.back();
                    long long mn = min(v[ind], v[i - 1]), mx = max(v[ind], v[i - 1]);
                    // cout << i << " " << ind << " " << h << " " << mn * (i - 1 - ind - 1) - find_sum(ind + 1, i - 1 - 1) << "\n";
                    ans = max(ans, mn * (i - 1 - ind - 1) - find_sum(ind + 1, i - 1 - 1));
                    if (h < v[i - 1])
                    {
                        index.pop_back();
                        height.pop_back();
                    }
                    else
                        break;
                }
                while (height.size() && height.back() == v[i - 1])
                {
                    index.pop_back();
                    height.pop_back();
                }
                index.push_back(i - 1);
                height.push_back(v[i - 1]);
            }
            prev = v[i];
        }
        cout << ans << "\n";
        // if (bruteforce() != ans)
        // {
        //     cout << "Here\n";
        //     for (int i = 0; i < 10; i++)
        //         cout << v[i] << " ";
        //     cout << "\n";
        //     cout << bruteforce() << " " << ans << "\n";
        //     break;
        // }
    }

    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    srand(time(0));
    solve();
    return 0;
}