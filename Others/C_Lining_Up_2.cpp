#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> child(n + 1, 0);
    int front;
    for (int i = 1; i <= n; i++)
    {
        int p;
        cin >> p;
        if (p == -1)
            front = i;
        else
            child[p] = i;
    }
    int cur = front;
    while (cur != 0)
    {
        cout << cur << " ";
        cur = child[cur];
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