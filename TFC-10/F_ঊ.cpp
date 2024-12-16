#include <bits/stdc++.h>
using namespace std;
struct pt
{
    long long x, y;
};
long long distance(pt a, pt b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
long long area(pt a, pt b, pt c)
{
    return a.x * b.y + b.x * c.y + c.x * a.y - a.y * b.x - b.y * c.x - c.y * a.x;
}
bool ok(pt a, pt b, pt c)
{
    if (area(a, b, c) == 0)
        return 0;
    long long ab = distance(a, b);
    long long bc = distance(b, c);
    long long ca = distance(c, a);
    if ((
            ab == bc ||
            bc == ca ||
            ca == ab) &&
        (ab != bc ||
         bc != ca ||
         ca != ab))
        return 1;
    return 0;
}
void solve()
{
    int n;
    while (cin >> n)
    {
        vector<pt> v(n);
        for (auto &[x, y] : v)
            cin >> x >> y;
        int count = 0;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                for (int k = j + 1; k < n; k++)
                    if (ok(v[i], v[j], v[k]))
                        count++;
        cout << count << "\n";
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