#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    vector<int> v;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'A')
            v.push_back(0);
        else if ((s[i] == 'B') && (i < s.size() - 1) && (s[i + 1] == 'C'))
            v.push_back(1), i++;
        else
            v.push_back(2);
    }
    long long cnt = 0, cur = 0;
    for (auto i : v)
    {
        if (i == 2)
        {
            cur = 0;
            continue;
        }
        if (i == 0)
            cur++;
        else
            cnt += cur;
    }
    cout << cnt << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}