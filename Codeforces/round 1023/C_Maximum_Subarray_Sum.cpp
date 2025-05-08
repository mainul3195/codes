#include <bits/stdc++.h>
using namespace std;
void solve()
{
    long long n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    long long mx = 0, loc_max = 0;
    vector<long long> v(n);
    for (auto &i : v)
        cin >> i;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            loc_max = 0;
            continue;
        }
        loc_max += v[i];
        if (loc_max < 0)
            loc_max = 0;
        mx = max(mx, loc_max);
    }
    if (mx > k)
    {
        cout << "No\n";
        return;
    }
    if (mx == k)
    {
        cout << "Yes\n";
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
                cout << "-1000000000000000000 ";
            else
                cout << v[i] << " ";
        }
        cout << "\n";
        return;
    }
    if (s[0] == '0')
    {
        cout << "Yes\n";
        int z = 0;
        while ((z + 1 < n) && (s[z + 1] == '0'))
            z++;
        if (z == n - 1)
        {
            cout << k << " ";
            for (int i = 1; i < n; i++)
                cout << "-1000000000000000000 ";
            cout << "\n";
            return;
        }
        long long mx = 0, sum = 0;
        for (int i = z + 1; (i < n) && (s[i] != '0'); i++)
        {
            sum += v[i];
            mx = max(mx, sum);
        }
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
            {
                if (i == z)
                {
                    cout << k - mx << " ";
                }
                else
                    cout << "-1000000000000000000 ";
            }
            else
                cout << v[i] << " ";
        }
        cout << "\n";
        return;
    }
    if (s[n - 1] == '0')
    {
        cout << "Yes\n";
        int z = n - 1;
        while ((z - 1 >= 0) && (s[z - 1] == '0'))
            z--;

        long long mx = 0, sum = 0;
        for (int i = z - 1; (i >= 0) && (s[i] != '0'); i--)
        {
            sum += v[i];
            mx = max(mx, sum);
        }

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
            {
                if (i == z)
                {
                    cout << k - mx << " ";
                }
                else
                    cout << "-1000000000000000000 ";
            }
            else
                cout << v[i] << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = n - 1; i > 0; i--)
    {
        if ((s[i] == '0') && (s[i - 1] == '0'))
        {
            long long mx = 0, sum = 0;
            for (int j = i + 1; (j < n) && (s[j] != '0'); j++)
            {
                sum += v[j];
                mx = max(mx, sum);
            }
            cout << "Yes\n";
            for (int j = 0; j < n; j++)
            {
                if (s[j] == '0')
                {
                    if (j == i)
                    {
                        cout << k - mx << " ";
                    }
                    else
                        cout << "-1000000000000000000 ";
                }
                else
                    cout << v[j] << " ";
            }
            cout << "\n";
            return;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            long long lmx = 0, rmx = 0, sum = 0;
            for (int j = i - 1; (j >= 0) && (s[j] != '0'); j--)
            {
                sum += v[j];
                lmx = max(lmx, sum);
            }
            sum = 0;
            for (int j = i + 1; (j < n) && (s[j] != '0'); j++)
            {
                sum += v[j];
                rmx = max(rmx, sum);
            }
            cout << "Yes\n";
            for (int j = 0; j < n; j++)
            {
                if (s[j] == '0')
                {
                    if (j == i)
                    {
                        cout << k - lmx - rmx << " ";
                    }
                    else
                        cout << "-1000000000000000000 ";
                }
                else
                    cout << v[j] << " ";
            }
            cout << "\n";
            return;
        }
    }
    cout << "No\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}