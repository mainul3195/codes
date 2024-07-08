#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    n <<= 1;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    sort(v.begin(), v.end());
    int i = 0, j = n - 1;
    while (i <= j)
    {
        cout << v[i] << " ";
        if (i != j)
        {
            cout << v[j] << " ";
            j--;
        }
        i++;
    }
    cout << "\n";
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