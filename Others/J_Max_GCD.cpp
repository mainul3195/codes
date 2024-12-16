#include <bits/stdc++.h>
using namespace std;
vector<long long> v;
long long n, k;
bool possible(long long d)
{
    long long mn = 0, pls = 0, tot = 0;
    vector<int> tmp;
    for (auto i : v)
        tmp.push_back(i % d);
    sort(tmp.begin(), tmp.end());       
    int start = 0, end = tmp.size() - 1;
    while (start < end)
    {
        int t = tmp[start];
        while (t--)
        {
            tmp[start]--;
            tmp[end]++;
            if (tmp[end] == d)
                end--;
        }
        tot += tmp[start];
        start++;
    }
    return tmp[end] == 0 && tot <= k;
}
void solve()
{
    cin >> n >> k;
    v = vector<long long>(n);
    long long sm = 0;
    for (auto &i : v)
    {
        cin >> i;
        sm += i;
    }
    long long lim = sqrt(sm + .5);
    vector<long long> divisors;
    for (int i = 1; i <= lim; i++)
    {
        if (sm % i == 0)
            divisors.push_back(i);
        if (sm / i != i)
            divisors.push_back(sm / i);
    }
    sort(divisors.rbegin(), divisors.rend());
    for (auto i : divisors)
        cout << i << " ";
    for (auto d : divisors)
    {
        if (possible(d))
        {
            cout << d << "\n";
            return;
        }
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