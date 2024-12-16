#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> v(150);
    for (int i = 33; i <= 126; i++)
        v[i] = i;
    while (q--)
    {
        char a, b;
        cin >> a >> b;
        int pa = 0, pb = 0;
        for (int i = 33; i <= 126; i++)
        {
            if (v[i] == a)
                pa = i;
            else if (v[i] == b)
                pb = i;
            if (pa & pb)
                break;
        }
        v[pa] = b;
        v[pb] = a;
    }
    for (auto c : s)
        cout << (char)v[c];
    cout << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}