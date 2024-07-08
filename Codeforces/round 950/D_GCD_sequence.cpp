#include <bits/stdc++.h>
using namespace std;
bool is_Sorted(vector<int> &v)
{
    for (int i = 1; i < v.size(); i++)
        if (v[i] < v[i - 1])
            return 0;
    return 1;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    vector<int> b;
    for (int i = 0; i < n - 1; i++)
        b.push_back(gcd(v[i], v[i + 1]));
    if (is_Sorted(b))
    {
        cout << "YES\n";
        return;
    }
    // for (auto i : b)
    //     cout << i << " ";
    // cout << "\n";
    vector<vector<int>> to_check;
    for (int i = 0; i < n - 2; i++)
        if (b[i] > b[i + 1])
        {
            if (i == 0)
            {
                vector<int> tmp = b;
                tmp[0] = tmp[1];
                to_check.push_back(tmp);
            }
            else
            {
                vector<int> tmp = b;
                tmp[i - 1] = gcd(v[i - 1], v[i + 1]);
                tmp[i] = tmp[i - 1];
                to_check.push_back(tmp);
            }
            if (i == n - 3)
            {
                vector<int> tmp = b;
                tmp[n - 2] = tmp[n - 3];
                to_check.push_back(tmp);
            }
            else
            {
                vector<int> tmp = b;
                tmp[i + 2] = gcd(v[i + 1], v[i + 3]);
                tmp[i + 1] = tmp[i];
                to_check.push_back(tmp);
            }
            vector<int> tmp = b;
            tmp[i + 1] = gcd(v[i], v[i + 2]);
            tmp[i] = tmp[i + 1];
            to_check.push_back(tmp);
            break;
        }
    // for (auto vec : to_check)
    // {
    //     for (auto i : vec)
    //         cout << i << " ";
    //     cout << "\n";
    // }
    for (auto vec : to_check)
        if (is_Sorted(vec))
        {
            cout << "YES\n";
            return;
        }
    cout << "NO\n";
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