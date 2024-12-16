#include <bits/stdc++.h>
using namespace std;
vector<bool> taken;
set<string> st;
string cur;
string s;
void permute(int i = 0)
{
    if (i == s.size())
    {
        st.insert(cur);
        return;
    }
    for (int x = 0; x < s.size(); x++)
    {
        if (!taken[x])
        {
            taken[x] = 1;
            cur.push_back(s[x]);
            permute(i + 1);
            taken[x] = 0;
            cur.pop_back();
        }
    }
    return;
}
void solve()
{
    cin >> s;
    int k;
    cin >> k;
    taken = vector<bool>(s.size() + 1, 0);
    permute();
    vector<string> all(st.begin(), st.end());
    cout << all[k - 1] << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}