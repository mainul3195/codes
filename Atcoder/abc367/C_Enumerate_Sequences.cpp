#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<int> r, stck;
void okdone(int sum = 0, int i = 0)
{
    if (i == n)
    {
        if (sum % k == 0)
        {
            for (auto j : stck)
                cout << j << " ";
            cout << "\n";
        }
        return;
    }
    for (int j = 1; j <= r[i]; j++)
    {
        stck.push_back(j);
        sum += j;
        okdone(sum, i + 1);
        stck.pop_back();
        sum -= j;
    }
    return;
}
void solve()
{
    cin >> n >> k;
    r = vector<int>(n);
    for (auto &i : r)
        cin >> i;
    okdone();
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}