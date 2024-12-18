#include <bits/stdc++.h>
using namespace std;
#define int long long
int mex(int a, int b)
{
    if (a > b)
        swap(a, b);
    if (a == 0 && b == 1)
        return 2;
    if (a == 0 && b == 2)
        return 1;
    return 0;
}
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<vector<int>> col(3, vector<int>(n + 2, 0));
    vector<int> ar(n + 1);
    for (int i = 0; i < n; i++)
    {
        int ind;
        if (s[i] == 'R')
            ind = 0;
        else if (s[i] == 'G')
            ind = 1;
        else
            ind = 2;
        col[ind][i + 1]++;
        ar[i + 1] = ind;
    }
    for (int i = 0; i < 3; i++)
        for (int j = 1; j <= n; j++)
            col[i][j] += col[i][j - 1];
    int ans = 0;
    for (int i = 1; i < n; i++)
        for (int j = i + 1; j < n; j++)
        {
            if (ar[i] != ar[j])
            {
                int mx = mex(ar[i], ar[j]);
                ans += col[mx][n] - col[mx][j];
                int dif = j - i;
                int tar = j + dif;
                if (tar <= n && ar[tar] == mx)
                    ans--;
            }
        }
    cout << ans << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}