#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<pair<int, string>>v;
    for(int i = 1; i<=6; i++)
    {
        string s;
        int pt, pu, rt, ru, f;
        cin >> s >> pt >> pu >> rt >> ru >> f;
        double sc = (.06*pt + .14*pu + .24*rt + .56*ru + .03*f);
        int score = (sc*100)+.05;
        v.push_back({score, s});
    }
    sort(v.rbegin(), v.rend());
    // for(auto [a, b]: v)
    //     cout << a << " " << b << "\n"; 
    int pos;
    for(int i = 1; i<=6; i++)
        if(v[i-1].second == "Taiwan")
        {
            pos = i;
            break;
        }
    // cout << "pos = " << pos << "\n";
    cout << (n/6 + (n%6>=pos)) << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve(); 
    return 0;
}