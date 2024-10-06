#include <bits/stdc++.h>
using namespace std;
vector<vector<long long>> p;
vector<long long> prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

void solve()
{

    return;
}
long long okdone(int taken, int i)
{
    if(taken == 0)
        return 0;
    
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    p = vector<vector<long long>> (101, vector<long long> (101, 0));
    for (int i = 0; i < prime.size(); i++)
        for (int j = prime[i]; j <= 100; j *= prime[i])
        {
            int start = j;
            int end = j * prime[i] - 1;
            for (int k = start; k <= 100; k++)
                p[k][prime[i]]++;
        }
    
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}