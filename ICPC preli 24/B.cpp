#include <bits/stdc++.h>
using namespace std;
struct PT
{
    int x;
    int y;
};

// Given three collinear PTs p, q, r, the function checks if
// PT q lies on line segment 'pr'
bool onSegment(PT p, PT q, PT r)
{
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
        return true;

    return false;
}

// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are collinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(PT p, PT q, PT r)
{
    // See https://www.geeksforgeeks.org/orientation-3-ordered-PTs/
    // for details of below formula.
    long long val = (long long)(q.y - p.y) * (r.x - q.x) -
                    (long long)(q.x - p.x) * (r.y - q.y);

    if (val == 0)
        return 0; // collinear

    return (val > 0) ? 1 : 2; // clock or counterclock wise
}

// The main function that returns true if line segment 'p1q1'
// and 'p2q2' intersect.
bool doIntersect(PT p1, PT q1, PT p2, PT q2)
{
    // Find the four orientations needed for general and
    // special cases
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    // General case
    if (o1 != o2 && o3 != o4)
        return true;

    // Special Cases
    // p1, q1 and p2 are collinear and p2 lies on segment p1q1
    if (o1 == 0 && onSegment(p1, p2, q1))
        return true;

    // p1, q1 and q2 are collinear and q2 lies on segment p1q1
    if (o2 == 0 && onSegment(p1, q2, q1))
        return true;

    // p2, q2 and p1 are collinear and p1 lies on segment p2q2
    if (o3 == 0 && onSegment(p2, p1, q2))
        return true;

    // p2, q2 and q1 are collinear and q1 lies on segment p2q2
    if (o4 == 0 && onSegment(p2, q1, q2))
        return true;

    return false; // Doesn't fall in any of the above cases
}
struct wire
{
    int id, u, v, company, ase;
};
struct st_el
{
    int id, cnt;
    bool operator<(const st_el &a) const
    {
        return cnt > a.cnt || (cnt == a.cnt && id < a.id);
    }
};
int cross_freq[30000];
void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i <= m; i++)
        cross_freq[i] = 0;
    vector<PT> routers(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> routers[i].x >> routers[i].y;
    vector<wire> wires(m + 1);
    for (int i = 1; i <= m; i++)
    {
        int u, v, com;
        cin >> u >> v >> com;
        wires[i] = {i, u, v, com, 1};
    }
    for (int i = 1; i <= m; i++)
        for (int j = i + 1; j <= m; j++)
            if ((wires[i].company != wires[j].company) && doIntersect(routers[wires[i].u], routers[wires[i].v], routers[wires[j].u], routers[wires[j].v]))
            {
                cross_freq[wires[i].id]++;
                cross_freq[wires[j].id]++;
            }
    set<st_el> st;
    for (int i = 1; i <= m; i++)
        st.insert({i, cross_freq[i]});
    vector<int> removed;
    while (st.size() && ((*st.begin()).cnt))
    {
        auto it = st.begin();
        auto [id1, cnt] = *it;
        st.erase(it);
        removed.push_back(id1);
        cross_freq[id1] = 0;
        wires[id1].ase = 0;
        for (auto [id2, u, v, com, ase] : wires)
            if (ase && (com != wires[id1].company))
            {
                if (doIntersect(routers[wires[id1].u], routers[wires[id1].v], routers[wires[id2].u], routers[wires[id2].v]))
                {
                    auto it1 = st.find({id2, cross_freq[id2]});
                    st.erase(it1);
                    cross_freq[id2]--;
                    st.insert({id2, cross_freq[id2]});
                }
            }
    }
    sort(removed.begin(), removed.end());
    cout << removed.size() << "\n";
    for (auto i : removed)
        cout << i << " ";
    cout << "\n";

    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, tc = 0;
    cin >> t;
    while (t--)
    {
        cout << "Case #" << ++tc << ":\n";
        solve();
    }
    return 0;
}