#include <bits/stdc++.h>
using namespace std;
struct nd
{
    char c;
    int a, b;
};
int n, q;
vector<int> salary;
int bit[600000];
vector<nd> query;
set<int> st;
unordered_map<int, int> mp;
int cnt;
void update(int ind, int v)
{
    for (; ind <= cnt; ind += (ind & (-ind)))
        bit[ind] += v;
    return;
}
long long sum(int ind)
{
    long long tot = 0;
    for (; ind > 0; ind -= (ind & (-ind)))
        tot += bit[ind];
    return tot;
}
void solve()
{
    cin >> n >> q;
    salary = vector<int>(n);
    for (auto &i : salary)
    {
        cin >> i;
        st.insert(i);
    }
    query = vector<nd>(q);
    for (auto &[a, b, c] : query)
    {
        cin >> a >> b >> c;
        st.insert(c);
        if (a == '?')
            st.insert(b);
    }
    cnt = 1;
    while (st.size())
    {
        auto it = st.begin();
        mp[*it] = cnt++;
        st.erase(it);
    }
    for (auto &i : salary)
        i = mp[i];
    for (auto &[a, b, c] : query)
    {
        c = mp[c];
        if (a == '?')
            b = mp[b];
    }
    // cout << "ok\n";
    memset(bit, 0, sizeof(bit));
    for (auto i : salary)
        update(i, 1);
    for (auto [a, b, c] : query)
    {
        if (a == '!')
        {
            b--;
            int s = salary[b];
            salary[b] = c;
            update(s, -1);
            update(c, 1);
        }
        else
            cout << sum(c) - sum(b - 1) << "\n";
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}