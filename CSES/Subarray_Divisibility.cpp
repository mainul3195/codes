#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    map<int, int> mp;
    mp[0] = 1;
    int sm = 0;
    long long count = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        (sm += a) %= n;
        (sm += n) %= n;
        count += mp[sm];
        mp[sm]++;
    }
    cout << count << "\n";
    return 0;
}