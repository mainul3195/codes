#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int>&a, pair<int, int>&b)
{
    return a.first>b.first || (a.first == b.first && a.second<b.second);
}
void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>>v;
    for(int i = 1; i<=n; i++)
    {
        string s;
        cin >> s;
        int win = 0;
        for(auto c: s)
            if(c=='o')
                win++;
        v.push_back({win, i});
    }
    // for(auto [a, b]: v)
    //     cout << a << " " << b << "\n";
    sort(v.begin(), v.end(), cmp);
    for(auto [a, b]: v)
        cout << b << " ";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve(); 
    return 0;
}