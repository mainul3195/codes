#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int>mx(3);
    cin >> mx[0] >> mx[1] >> mx[2];
    for(int i = 1; i<n; i++)
    {
        vector<int>tmp(3, 0);
        for(int j = 0; j<3; j++)
        {
            int a;
            cin >> a;
            if(j==0)
                tmp[j] = a+min(mx[1], mx[2]);
            else if(j==1)
                tmp[j] = a+min(mx[0], mx[2]);
            else tmp[j] = a+min(mx[0], mx[1]);
        }
        mx = tmp;
    }
    cout << min({mx[0], mx[1], mx[2]}) << "\n";
    return ;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, tc = 0;
    cin >> t;
    while(t--)
    {
        cout << "Case " << ++tc << ": ";
        solve();
    }
    return 0;
}