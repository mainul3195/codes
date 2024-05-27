#include<bits/stdc++.h>
using namespace std;
vector<int> v, nxt_count, nxt_node;
int n, m, k = 320;
void solve()
{
    cin >> n >> m;
    v = nxt_count = nxt_node = vector<int>(n, 0);
    for(int i = 0; i<n; i++)
        cin >> v[i];

    for(int i = 0; i<n; i++)
    {
        int strt = i;
        int cnt = 0;
        while(i<n && i/k == strt/k)
        {
            i = i+v[i];
            cnt++;
        }
        nxt_count[strt] = cnt;
        if(i>=n)
            i = n;
        nxt_node[strt] = i;
        i = strt;
    }


    for(auto i: v)
        cout << i << " ";
    cout << "\n";
    for(auto i: nxt_count)
        cout << i << " ";
    cout << "\n";
    for(auto i: nxt_node)
        cout << i << " ";
    cout << "\n";
    // cout << "Ok\n";

    // for(int i = 1; i<=m; i++)
    // {
    //     int t;
    //     cin >> t;
    //     if(t==1)
    //     {
    //         int cur;
    //         cin >> cur;
    //         int last = cur, tot = 0;
    //         while(cur<n)
    //         {
    //             tot += nxt_count[cur];
    //             last = cur;
    //             cur = nxt_node[cur];
    //         }
    //         cout << tot << " " << last << "\n";
    //     }
    //     else
    //     {
    //         int ind, val;
    //         cin >> ind >> val;
    //     }
    // }


    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve(); 
    return 0;
}