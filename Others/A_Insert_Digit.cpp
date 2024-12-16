#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int n, d;
    cin >> n >> d;
    string s;
    cin >> s;
    bool done = 0;
    for(int i = 0; i<n; i++)
    {
        if(s[i]-'0'<d && !done)
        {
            done = 1;
            cout << d;
        }
        cout << s[i];
    }
    if(!done)
        cout << d;
    cout << "\n";
    return;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}