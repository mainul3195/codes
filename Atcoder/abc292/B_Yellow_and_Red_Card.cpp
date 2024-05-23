#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, q;
    cin >> n >> q;
    map<int, int> mp;
    while(q--)
    {
        int t, x;
        cin >> t >> x;
        if(t==1)
            mp[x]++;
        else if(t==2)
            mp[x]+=2;
        else
        {
            if(mp[x]<2)
                cout << "No\n";
            else cout << "Yes\n";
        }
    }
    return 0;

}