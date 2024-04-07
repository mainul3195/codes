#include <bits/stdc++.h>
using namespace std;
struct pr
{
    int a, b;
    bool operator<(const pr &x) const
    {
        return b < x.b || (b == x.b && a < x.a);
    }
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pr> v(n);
    for (auto &[a, b] : v)
        cin >> a >> b;

    map<int, vector<int>> end;
    map<int, int> start;
    set<int> st;
    for (auto [a, b] : v)
    {
        end[b].push_back(a);
        start[a] = 1;
        st.insert(a);
        st.insert(b);
    }
    set<int> began;
    sort(v.begin(), v.end());
    int count = 0;
    for (auto i : st)
    {
        if (end[i].size() > 0)
        {
            bool done = 0;
            for (auto j : end[i])
            {
                auto it = began.lower_bound(j);
                if (it != began.end() && *it == j)
                {
                    count++;
                    began.clear();
                    done = 1;
                    break;
                }
            }
        }
        if (start[i] > 0)
            began.insert(i);
    }
    cout << count << "\n";
    return 0;
}