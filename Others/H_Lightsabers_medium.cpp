#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<int> k, col;
bool possible(int x)
{
    vector<int> tmp(m+1, 0);
    int l = 0, r = 0;
    tmp[col[l]]++;
    int extra = 10000000;
    while(r<n)
    {
        if(tmp[col[l]]>k[col[l]])
        {
            l++;
            tmp[col[l]]--;
        }
        else
        {
            r++;
            tmp[col[r]]++;

        }
        if(r-l+1-e == sm)
        {
            extra = min(extra, e);
        }
    }
    
}
void solve()
{
    cin >> n >> m;
    k = vector<int> (m+1, 0);
    col = vector<int>(n);
    for(auto &i: col)
        cin >> i;
    for(int i = 1; i<=m; i++)
        cin >> k[i];
    int sm = 0;
    for(auto i: k)
        sm += i;
    int l = 0, r = n-sm, mid, ans = -1;
    while(l<=r)
    {
        mid = (l+r)/2;
        if(possible(mid))
        {
            ans = mid;
            r = mid-1;
        }
        else l = mid+1;
    }
    cout << ans << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve(); 
    return 0;
}