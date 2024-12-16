#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    int lft = -1, rt = 100000000;
    for(int i = 0; i<k; i++)
    {
        int l, r;
        cin >> l >> r;
        lft = max(lft, l);
        rt = min(rt, r);
    }
    cout << max(0, rt-lft+1) << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve(); 
    return 0;
}