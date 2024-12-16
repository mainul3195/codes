#include <bits/stdc++.h>
using namespace std;
struct r
{
    int a, b;
};
vector<r> v(4);
bool varify_5(r m, r n, r o, r p)
{
    return (m.a == n.a) && (o.a == p.a) && (m.a + o.a == n.a + p.a) && (m.b + n.b == o.b + p.b) && (o.b + p.b == m.a + o.a);
}
bool possible_5(int i = 0)
{
    if (i == 4)
    {
        vector<int> index = {0, 1, 2, 3};
        int ok = 0;
        do
        {
            // for(auto j : index)
            //     cout << j << " ";
            // cout << "\n";
            ok |= varify_5(v[index[0]], v[index[1]], v[index[2]], v[index[3]]);
        } while (next_permutation(index.begin(), index.end()));
        return ok;
    }
    int ok1 = 0, ok2 = 0;
    ok1 = possible_5(i + 1);
    swap(v[i].a, v[i].b);
    ok2 = possible_5(i + 1);
    swap(v[i].a, v[i].b);
    return ok1 || ok2;
}
bool varify_4(r &m, r &n, r &o, int &mx, int &w)
{
    return (n.b == o.b) && (n.a + o.a + w == mx) && (w + m.a == mx) && (m.b + n.b == mx) && (n.a + o.a == m.a);
}
bool possible_4(int &mx, int &w, vector<r> &rem, int i = 0)
{
    if (i == 3)
    {
        vector<int> index = {0, 1, 2};
        int ok = 0;
        do
        {
            ok |= varify_4(rem[index[0]], rem[index[1]], rem[index[2]], mx, w);
        } while (next_permutation(index.begin(), index.end()));
        return ok;
    }
    int ok1 = 0, ok2 = 0;
    ok1 = possible_4(mx, w, rem, i + 1);
    swap(rem[i].a, rem[i].b);
    ok2 = possible_4(mx, w, rem, i + 1);
    swap(rem[i].a, rem[i].b);
    return ok1 || ok2;
}

bool varify_3(r &m, r &n, r &o, int &mx, int &w)
{
    return (m.a == n.a) && (n.a == o.a) && (m.b + n.b + o.b == mx) && (m.a + w == mx);
}
bool possible_3(int &mx, int &w, vector<r> &rem, int i = 0)
{
    if (i == 3)
    {
        vector<int> index = {0, 1, 2};
        int ok = 0;
        do
        {
            ok |= varify_3(rem[index[0]], rem[index[1]], rem[index[2]], mx, w);
        } while (next_permutation(index.begin(), index.end()));
        return ok;
    }
    int ok1 = 0, ok2 = 0;
    ok1 = possible_3(mx, w, rem, i + 1);
    swap(rem[i].a, rem[i].b);
    ok2 = possible_3(mx, w, rem, i + 1);
    swap(rem[i].a, rem[i].b);
    return ok1 || ok2;
}
void solve()
{
    for (auto &[a, b] : v)
        cin >> a >> b;
    int mx, mx_count;
    mx = 0, mx_count = 0;
    for (auto [a, b] : v)
        mx = max({mx, a, b});
    for (auto [a, b] : v)
        if (a == mx || b == mx)
            mx_count++;

    // case 1
    if (mx_count == 4)
    {
        int rest = 0;
        for (auto [a, b] : v)
        {
            if (a == mx)
                rest += b;
            else
                rest += a;
        }
        if (rest == mx)
        {
            cout << "Yes\n";
            return;
        }
    }

    // case 2
    if (mx_count == 2)
    {
        int w = 0;
        vector<r> rem;
        for (auto [a, b] : v)
            if (a == mx || b == mx)
            {
                if (a == mx)
                    w += b;
                else
                    w += a;
            }
            else
                rem.push_back({a, b});
        auto [a, b] = rem[0];
        auto [c, d] = rem[1];
        if ((a == c) && (w + a == mx))
        {
            if (b + d == mx)
            {
                cout << "Yes\n";
                return;
            }
        }
        if ((a == d) && (w + a == mx))
        {
            if (b + c == mx)
            {
                cout << "Yes\n";
                return;
            }
        }
        if ((b == c) && (w + b == mx))
        {
            if (a + d == mx)
            {
                cout << "Yes\n";
                return;
            }
        }
        if ((b == d) && (w + b == mx))
        {
            if (a + c == mx)
            {
                cout << "Yes\n";
                return;
            }
        }
    }

    // case 3
    if (mx_count == 1)
    {
        int w = 0;
        vector<r> rem;
        for (auto [a, b] : v)
            if (a == mx || b == mx)
            {
                if (a == mx)
                    w += b;
                else
                    w += a;
            }
            else
                rem.push_back({a, b});
        if (possible_3(mx, w, rem))
        {
            cout << "Yes\n";
            return;
        }
    }

    // case 4
    if (mx_count == 1)
    {
        int w = 0;
        vector<r> rem;
        for (auto [a, b] : v)
            if (a == mx || b == mx)
            {
                if (a == mx)
                    w += b;
                else
                    w += a;
            }
            else
                rem.push_back({a, b});
        if (possible_4(mx, w, rem))
        {
            cout << "Yes\n";
            return;
        }
    }

    // case 5
    if (possible_5())
    {
        cout << "Yes\n";
        return;
    }
    cout << "No\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}