#include <bits/stdc++.h>
using namespace std;
int n, q;
#define lim 1000005

vector<int> spf(lim + 1, 0);
void smallest_pf()
{
    for (int i = 2; i <= lim; i += 2)
        spf[i] = 2;
    for (int i = 3; i * i <= lim; i += 2)
        if (!spf[i])
            for (int j = i; j <= lim; j += 2 * i)
                spf[j] = i;
    for (int i = 3; i <= lim; i += 2)
        if (!spf[i])
            spf[i] = i;
    return;
}
void prime_factorization(int x, vector<int> &v)
{
    // cout << "here -> " << x << " " << spf[x] << "\n";
    while (x != 1)
    {
        v.push_back(spf[x]);
        int p = spf[x];
        while (x % p == 0)
            x = x / spf[x];
    }
    return;
}
long long ans = 0, tot = 0;
vector<int> no_name;
void add(int x)
{
    vector<int> v;
    prime_factorization(x, v);
    // for (auto i : v)
    //     cout << i << " ";
    // cout << "ok\n";
    int limit = (1 << v.size());
    int non_co_primes = 0;
    for (int i = 1; i < limit; i++)
    {
        int cur = 1, cnt = 0;
        for (int j = 0; j < v.size(); j++)
        {
            if (i & (1 << j))
                cur *= v[j], cnt++;
        }
        // cout << "Here -> " << cur << "\n";
        if (cnt & 1)
            non_co_primes += no_name[cur];
        else
            non_co_primes -= no_name[cur];
        no_name[cur]++;
    }
    ans += tot - non_co_primes;
    tot++;
    return;
}
void remove(int x)
{
    vector<int> v;
    prime_factorization(x, v);
    int limit = (1 << v.size());
    for (int i = 1; i < limit; i++)
    {
        int cur = 1;
        for (int j = 0; j < v.size(); j++)
        {
            if (i & (1 << j))
                cur *= v[j];
        }
        no_name[cur]--;
    }
    tot--;
    int non_co_primes = 0;
    for (int i = 1; i < limit; i++)
    {
        int cur = 1, cnt = 0;
        for (int j = 0; j < v.size(); j++)
        {
            if (i & (1 << j))
                cur *= v[j], cnt++;
        }
        if (cnt & 1)
            non_co_primes += no_name[cur];
        else
            non_co_primes -= no_name[cur];
    }
    ans -= tot - non_co_primes;
    return;
}
void print_no_name()
{
    for (int i = 1; i <= n; i++)
        cout << i << " -> " << no_name[i] << "\n";
    cout << "\n";
    return;
}
void solve()
{
    cin >> n >> q;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;
    no_name = vector<int>(500005, 0);
    vector<bool> present(500005, 0);

    // print_no_name();
    // add(1);
    // print_no_name();
    // cout << tot << " " << ans << "\n";
    // add(1);
    // print_no_name();
    // cout << tot << " " << ans << "\n";
    // add(3);
    // print_no_name();
    // cout << tot << " " << ans << "\n";
    // add(4);
    // print_no_name();
    // cout << tot << " " << ans << "\n";
    // add(6);
    // print_no_name();
    // cout << tot << " " << ans << "\n";
    // remove(1);
    // print_no_name();
    // cout << tot << " " << ans << "\n";
    // return;
    while (q--)
    {
        int x;
        cin >> x;
        x--;
        if (!present[x])
            add(a[x]);
        else
            remove(a[x]);
        present[x] = !present[x];

        // cout << x << "-> \n";
        cout << ans << "\n";
    }
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    smallest_pf();
    solve();
    return 0;
}