// #include <bits/stdc++.h>
// using namespace std;
// vector<vector<int>> grundy(5000, vector<int>(2, -1));
// int mex(set<int> st)
// {
//     int i = 0;
//     for (auto el : st)
//     {
//         if (el != i)
//             break;
//         i++;
//     }
//     return i;
// }
// int lim;
// int find_grundy(int n, int move = 0)
// {
//     set<int> st;
//     if (move == 0)
//     {
//         for (int i = 2; i <= lim && i <= n; i += 2)
//             st.insert(find_grundy(n - i, !move));
//     }
//     else
//     {
//         for (int i = 1; i <= lim && i <= n; i += 2)
//             st.insert(find_grundy(n - i, !move));
//     }
//     return mex(st);
// }
// void solve()
// {
//     grundy[0][0] = grundy[0][1] = 0;
//     for (int i = 1; i <= 17; i++)
//     {
//         lim = i / 2;
//         cout << i << " -> " << find_grundy(i, 1) << "\n";
//     }
//     return;
// }
// int main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     solve();
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n, p;
    cin >> n >> p;
    if (p == 2)
    {
        if (n < 5)
            cout << "Oddius\n";
        else
        {
            if ((n - 1) % 4 == 0)
                cout << "Evenius\n";
            else
                cout << "Oddius\n";
        }
        return;
    }
    if (n == 1)
        cout << "Evenius\n";
    else
        cout << "Oddius\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, tc = 0;
    cin >> t;
    while (t--)
    {
        cout << "Case " << ++tc << ": ";
        solve();
    }
    return 0;
}