#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    sort(v.begin(), v.end());
    int count = 0;
    int s = 0, e = n - 1;
    while (s <= e)
    {
        count++;
        if (s == e)
            break;
        if (v[s] + v[e] <= x)
            s++, e--;
        else
            e--;
    }
    cout << count << "\n";
    return 0;
}