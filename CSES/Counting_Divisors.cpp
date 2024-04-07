#include <bits/stdc++.h>
using namespace std;
#define lim 1000006
vector<long long> ans;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ans = vector<long long>(lim + 1, 1);
    for (int i = 2; i <= lim; i++)
        for (int j = i; j <= lim; j += i)
            ans[j]++;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << ans[n] << "\n";
    }
    return 0;
}