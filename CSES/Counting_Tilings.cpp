#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
int n, m;
long long dp[1003][1 << 10 + 2];
void generate_next_masks(const int &mask, vector<int> &next_masks, int i = 0, int tmp = 0)
{
    if (i >= n)
    {
        next_masks.push_back(tmp);
        return;
    }
    if (!(mask & (1 << i)))
    {
        generate_next_masks(mask, next_masks, i + 1, tmp | (1 << i));
        if (i + 1 < n && !(mask & (1 << (i + 1))))
            generate_next_masks(mask, next_masks, i + 2, tmp);
    }
    else
        generate_next_masks(mask, next_masks, i + 1, tmp);
    return;
}
long long okdone(int i = 0, int mask = 0)
{
    if (i == m)
        return mask == 0;
    if (~dp[i][mask])
        return dp[i][mask];
    vector<int> next_masks;
    generate_next_masks(mask, next_masks);
    long long res = 0;
    for (auto next_mask : next_masks)
        (res += okdone(i + 1, next_mask)) %= mod;
    return dp[i][mask] = res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    memset(dp, -1, sizeof(dp));
    cout << okdone() << "\n";
    return 0;
}