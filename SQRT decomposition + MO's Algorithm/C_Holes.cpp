#include<bits/stdc++.h>
using namespace std;
vector<int> v, nxt_count, nxt_node;
int n, m, k = 320;
bool dif(int i, int j)
{
    if(i/k != j/k)
        return 1;
    if(j>=n)
        return 1;
    return 0;
}
void solve()
{
    cin >> n >> m;
    v = nxt_count = nxt_node = vector<int>(n+1, 0);
    for(int i = 0; i<n; i++)
        cin >> v[i];

    for(int i = 0; i<n; i++)
    {
        int strt = i;
        int cnt = 0;
        while(i<n && (i/k == strt/k))
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


    for(int i = 1; i<=m; i++)
    {
        int t;
        cin >> t;
        if(t==1)
        {
            int cur;
            cin >> cur;
            cur--;
            int tot = 0, last = cur;
            while(nxt_node[cur] != n)
            {
                tot += nxt_count[cur];
                last = cur;
                cur = nxt_node[cur];
            }
            while(cur<n)
            {
                tot ++;
                last = cur;
                cur = cur+v[cur];
            }
            cout << last+1 << " " << tot << "\n";
        }
        else
        {
            int ind, val;
            cin >> ind >> val;
            ind--;
            v[ind] = val;
            int strt = (ind/k)*k;
            int end = (ind/k+1)*k;
            end--;
            if(end>=n)
                end = n-1;
            for(int i = end; i>=strt; i--)
            {
                int nxt = i+v[i];
                if(nxt>n)
                    nxt = n;
                if(dif(i, nxt))
                    nxt_node[i] = nxt, nxt_count[i] = 1;
                else
                    nxt_node[i] = nxt_node[nxt], nxt_count[i] = nxt_count[nxt]+1;
            }
        }
    }


    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve(); 
    return 0;
}
