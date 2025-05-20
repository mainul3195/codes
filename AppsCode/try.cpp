#include <bits/stdc++.h>
using namespace std;
struct node
{
    int val;
    map<string, node *> mp;
    node()
    {
        val = 0;
    }
    node(int x)
    {
        val = x;
    }
};
void add(node *cur, string s, int x)
{
    if (s.empty())
    {
        cur->val += x;
        return;
    }
    string name = "";
    while (s.size() && s.back() != '/')
    {
        name += s.back();
        s.pop_back();
    }
    if (s.size())
        s.pop_back();
    if (cur->mp.find(name) == cur->mp.end())
        cur->mp[name] = new node();
    add(cur->mp[name], s, x);
    return;
}

int mx = -1;
string max_val_path;
void update(node *cur, string path = "", int xr = 0)
{
    xr ^= cur->val;
    if (xr > mx)
    {
        mx = xr;
        max_val_path = path;
    }
    for (auto [a, b] : cur->mp)
        update(b, path + a + '/', xr);
    return;
}

void Print(node *cur, string path = "")
{
    cout << path << " -> " << cur->val << "\n";
    for (auto [a, b] : cur->mp)
        Print(b, path + a + '/');
    return;
}
void solve()
{
    node *root = new node();
    int q;
    cin >> q;
    while (q--)
    {
        string s;
        int val;
        cin >> s >> val;
        reverse(s.begin(), s.end());
        add(root, s, val);
        mx = -1, max_val_path = "";
        update(root);
        // reverse(s.begin(), s.end());
        // cout << "After update: " << s << "\n";
        // Print(root);
        cout << max_val_path << "\n";
    }

    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}