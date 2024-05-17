#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> p(n);
    for(auto &i: p)
        cin >> i;
    vector<int>v;
    for(int i = 1; i<n-1; i+=2)
        v.push_back(p[i]);
    map<int, int> mp;
    sort(v.begin(), v.end());
    int last = n;
    for(int i: v)
        mp[i] = last--;
    int start = 1;
    v.clear();
    for(int i = 0; i<n; i+=2)
        v.push_back(p[i]);
    sort(v.rbegin(), v.rend());
    for(auto i: v)
        mp[i] = start++;
    mp[p[n-1]] = start;
    vector<int>a1(n);
    for(int i = 0; i<n; i++)
        a1[i] = mp[p[i]];

    v.clear();
    for(int i = 2; i<n-1; i+=2)
        v.push_back(p[i]);
    mp.clear();
    sort(v.begin(), v.end());
    last = n;
    for(int i: v)
        mp[i] = last--;
    start = 1;
    v.clear();
    for(int i = 1; i<n; i+=2)
        v.push_back(p[i]);
    sort(v.rbegin(), v.rend());
    for(auto i: v)
        mp[i] = start++;
    mp[p[0]] = start;
    vector<int>a2(n);
    for(int i = 0; i<n; i++)
        a2[i] = mp[p[i]];
    int ans1 = 0, ans2 = 0;
    for(int i = 1; i<n-1; i++)
    {
        int a = p[i-1]+a1[i-1], b = p[i]+a1[i], c = p[i+1]+a1[i+1];
        if(b>a && b>c)
            ans1++;
        a = p[i-1]+a2[i-1], b = p[i]+a2[i], c = p[i+1]+a2[i+1];
        if(b>a && b>c)
            ans2++;
    }
    if(ans1<ans2)
        a1 = a2;
    for(auto i: a1)
        cout << i << " ";
        cout << "\n";
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