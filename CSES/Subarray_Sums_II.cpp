#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    map<long long, int> mp;
    mp[0] = 1;
    long long count = 0;
    long long sm = 0;
    for (int i = 1; i <= n; i++)
    {
        long long a;
        cin >> a;
        sm += a;
        if (mp.count(sm - x))
            count += mp[sm - x];
        mp[sm]++;
    }
    cout << count << "\n";
    return 0;
}