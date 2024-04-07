#include <bits/stdc++.h>
using namespace std;
struct nd
{
    long long val, ind;
    bool operator<(const nd &a) const
    {
        return val < a.val;
    }
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    vector<nd> v(n);
    int count = 1;
    for (auto &[val, ind] : v)
    {
        cin >> val;
        ind = count++;
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
    {
        int k = n - 1;
        for (int j = i + 1; j < k; j++)
        {
            int need = x - v[i].val - v[j].val;
            while (v[k].val > need && k && j < k)
                k--;
            if (v[k].val == need && j != k)
            {
                cout << v[i].ind << " " << v[j].ind << " " << v[k].ind << '\n';
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}