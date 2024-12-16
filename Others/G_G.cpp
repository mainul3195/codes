#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    string s;
    cin >> n >> k >> s;
    string sorted;
    sorted = s;
    sort(sorted.begin(), sorted.end());
    int last = k / 2;
    int frst = k - last;
    // cout << frst << " " << last << "\n";
    multiset<char> st;
    for (int i = 0; i < frst; i++)
        st.insert(sorted[i]);
    // for (auto i : st)
    //     cout << i << " ";
    // cout << "\n";
    for (int i = n - 1; st.size(); i--)
    {
        auto it = st.find(s[i]);
        if (it != st.end())
        {
            st.erase(it);
            s[i] = '.';
        }
    }
    string tmp = sorted.substr(0, frst);
    for (int i = 0; i < n; i++)
        if (s[i] != '.')
            tmp += s[i];
    // cout << " _. " << tmp << "\n";
    // cout << tmp << "\n";
    string sesh = "";
    for (int i = 0, j = 0; sesh.size() < last && i < n && j < n;)
    {
        if (sorted[i] == tmp[j])
        {
            i++, j++;
            continue;
            ;
        }
        int nxt = j;
        while(nxt<n && tmp[j]!=)
        sesh.push_back(tmp[j]);
        tmp[j] = '.';
        j++;
    }
    // cout << tmp << "\n";
    sort(sesh.begin(), sesh.end());
    for (auto c : tmp)
        if (c != '.')
            cout << c;
    cout << sesh;
    cout << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}