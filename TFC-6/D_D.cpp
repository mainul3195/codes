#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long m, k;
    cin >> m >> k;
    if (k >= (1 << m))
        cout << "-1\n";
    else if (k == 0)
    {
        int lim = (1 << m);
        for (int i = 0; i < lim; i++)
            cout << i << " " << i << " \n"[i == lim - 1];
    }
    else
    {
        if (m == 1)
            cout << "-1\n";
        else if (m == 0)
            cout << "0 0\n";
        else
        {
            cout << k << " ";
            int lim = (1 << m);
            for (int i = 0; i < lim; i++)
                if (i != k)
                    cout << i << " ";
            cout << k << " ";
            for (int i = lim - 1; i >= 0; i--)
                if (i != k)
                    cout << i << " \n"[i == 0];
        }
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}