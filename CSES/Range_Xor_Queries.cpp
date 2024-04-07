#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    v.push_back(0);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        v.push_back(v.back() ^ x);
    }
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << (v[r] ^ v[l - 1]) << "\n";
    }
    return 0;
}