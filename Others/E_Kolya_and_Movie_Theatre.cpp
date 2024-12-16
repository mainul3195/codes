#include<bits/stdc++.h>
using namespace std;
void solve()
{
    long long n, m, d;
    cin >> n >> m >> d;
    multiset<long long> st;
    long long sum = 0, mx = 0;
    for(int i = 1; i<=n; i++)
    {
        long long a;
        cin >> a;
        if(a>0)
        {
            sum+=a;
            st.insert(a);
        }
        if(st.size()>m)        
        {
            sum -= *(st.begin());
            st.erase(st.begin());
        }
        mx = max(mx, sum - d*i);
    }
    cout << mx << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}