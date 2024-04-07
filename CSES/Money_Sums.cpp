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
    int mx = n * 1000 + 2;
    vector<int> dp(mx, -1);
    dp[0] = 1;
    for (auto i : v)
        for (int j = mx; j - i >= 0; j--)
            if (~dp[j - i])
                dp[j] = 1;
    vector<int> can_make;
    for (int i = 1; i <= mx; i++)
        if (dp[i] == 1)
            can_make.push_back(i);
    sort(can_make.begin(), can_make.end());
    cout << can_make.size() << '\n';
    for (auto i : can_make)
        cout << i << " ";
    cout << "\n";
    return 0;
}