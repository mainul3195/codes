#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int>v(n);
    set<int> st;
    for(int &i: v){
        cin >> i;
        st.insert(i);
    }

    if(st.size() == 1 || v[0] != v.back()){
        cout << "-1\n";
        return;
    }
    int sm = v[0];
    for(int i = 1; i<n-1; i++)
        if(v[i] != sm && ( !(v[i-1]==sm && v[i+1]==sm) ))
        {
            cout << "-1\n";
            return;
        }

    int ans = 1000000000;
    // cout << n << "\n";
    for(int i = 0; i<n; i++)
        if(v[i] == sm)
        {
            int cnt = 0;
            while(i<n && v[i] == sm)
            {
                cnt++;
                i++;
            }
            i--;
            ans = min(ans, cnt);
        }
    cout << ans << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve(); 
    return 0;
}