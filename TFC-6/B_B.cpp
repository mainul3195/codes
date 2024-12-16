#include <bits/stdc++.h>
using namespace std;
vector<long long> find_divs(long long n)
{
    vector<long long> v;
    int lim = sqrt(n + .5);
    for (int i = 1; i <= lim; i++)
        if (n % i == 0)
        {
            v.push_back(i);
            if (i != n / i)
                v.push_back(n / i);
        }
    sort(v.begin(), v.end());
    return v;
}
long long gcd(long long a, long long b)
{
    if (!b)
        return a;
    return gcd(b, a % b);
}
long long lcm(long long a, long long b)
{
    return a / gcd(a, b) * b;
}
void solve()
{
    int n;
    cin >> n;
    vector<long long> diva, divb;
    long long a, b;
    cin >> a >> b;
    diva = find_divs(a);
    divb = find_divs(b);
    vector<pair<long long, long long>> cards(n - 1);
    for (auto &[i, j] : cards)
        cin >> i >> j;
    long long ans = 0;
    for (auto x : diva)
        for (auto y : divb)
        {
            bool ok = 1;
            for (int i = 0; i < cards.size(); i++)
            {
                if ((gcd(x, cards[i].first) == x && gcd(y, cards[i].second) == y) || (gcd(x, cards[i].second) == x && gcd(y, cards[i].first) == y))
                    continue;
                ok = 0;
                break;
            }
            // if(x==2 && y==5)
            // {
            //     cout << "here -> " << ok  <<"\n";
            // }
            if (ok)
                ans = max(ans, lcm(x, y));
        }
    cout << ans << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}