#include<bits/stdc++.h>
using namespace std;

void solve()
{
    string a, b, aa, bb;
    cin >> a >> b;
    int i = 0;
    while(i<a.size() && a[i] == b[i]){
        aa.push_back(a[i]), bb.push_back(b[i]);
        i++;
    }
    bool bigger;
    if(i<a.size())
    {
        aa.push_back(a[i]);
        bb.push_back(b[i]);
        bigger = a[i]>b[i];
        i++;
    }
    if(i<a.size())
    {
        if(bigger)
            while(i<a.size())
            {
                aa.push_back(min(a[i], b[i]));
                bb.push_back(max(a[i], b[i]));
                i++;
            }
        else
            while(i<a.size())
            {
                bb.push_back(min(a[i], b[i]));
                aa.push_back(max(a[i], b[i]));
                i++;
            }
    }
    cout << aa << "\n" << bb << "\n";
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