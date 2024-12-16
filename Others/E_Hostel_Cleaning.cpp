#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<long long> v(n);
    for(auto &i: v)
        cin >> i;
    long long mn = 1e18;
    for(int i = 0; i<k; i++)
    {
        long long tmp = 0;
        for(int j = i; j<n; j+=k)
            tmp += v[j];
        mn = min(mn, tmp);
    }
    cout << mn << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve(); 
    return 0;
}