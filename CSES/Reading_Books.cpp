#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    long long mx = 0, sum = 0;
    for (int i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        mx = max(mx, x);
        sum += x;
    }
    cout << max(2 * mx, sum) << "\n";
    return 0;
}