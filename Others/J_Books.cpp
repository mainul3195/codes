#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<long long> books(n);
    for(auto &i: books)
        cin >> i;
    if(n==m)
        cout << "Richman\n";
    else
    {
        int z_count = 0, mn = 2000000000;
        for(auto i: books)
        {
            if(!i)
                z_count++;
            mn = min((long long)mn, i);
        }
        if(z_count>m)
        {
            cout << "Impossible\n";
            return;
        }
        if(m==0)
        {
            cout << mn-1 << "\n";
            return;
        }
        int need = m-z_count;
        long long tot = 0;
        vector<int>v(n);
        mn = 2000000000;
        for(int i = n-1; i>=0; i--)
        {
            if(books[i])
                mn = min((long long)mn, books[i]);
            v[i] = mn;
        }
        if(z_count == m)
        {
            cout << v[0]-1 << "\n";
            return;
        }
        int ind = 0;
        for(auto i: books)
        {
            if(i)
            {
                tot += i;
                need--;
                if(!need)
                {
                    tot += (v[ind+1]-1);
                    break;
                }
            }
            ind++;
        }
        cout << tot << "\n";
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}