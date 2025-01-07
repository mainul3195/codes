#include <bits/stdc++.h>
using namespace std;
int n;
vector<pair<int, int>> moves;
void okdone(int from, int via, int to, int n)
{
    if (n == 1)
    {
        moves.push_back({from, to});
        return;
    }
    okdone(from, to, via, n - 1);
    moves.push_back({from, to});
    okdone(via, from, to, n - 1);
    return;
}
void solve()
{
    cin >> n;
    okdone(1, 2, 3, n);
    cout << moves.size() << "\n";
    for (auto [a, b] : moves)
        cout << a << " " << b << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}