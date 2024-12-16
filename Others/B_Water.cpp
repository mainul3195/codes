#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n, c;
    cin >> n >> c;
    int cnt = 1;
    int cur = c;
    for(int i = 0; i<n; i++)
    {
        int x;
        cin >> x;
        if(x>=cur)
        {
            cur = c;
            cnt++;
        }
        else cur-=x;
    }
    cout << cnt << "\n";
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