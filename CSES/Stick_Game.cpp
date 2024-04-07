#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<int>moves;
vector<int>pos;
void solve()
{
    cin >> n >> k;
    moves = vector<int>(k);
    pos = vector<int>(n+1, 0);
    for(auto &i: moves)
        cin >> i;
    for(int i = 1; i<=n; i++)
    {
        for(auto m: moves)
            if(i-m>=0 && !pos[i-m])
            {
                pos[i] = 1;
                break;
            }
    }
    for(int i = 1; i<=n; i++)
    {        
        if(pos[i])
            cout << "W";
        else cout << "L";
    }
    cout << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}