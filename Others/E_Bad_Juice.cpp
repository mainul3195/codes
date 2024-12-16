#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cout.flush();
    cin >> n;
    n--;
    int bd = 0;
    int t = n;
    while (n)
    {
        n >>= 1;
        bd++;
    }
    cout << bd << endl;
    n = t;
    vector<vector<int>> per(bd + 1);
    for (int i = 1; i <= n; i++)
    {
        int ind = 1;
        int j = i;
        while (j)
        {
            if (j & 1)
                per[ind].push_back(i + 1);
            ind++;
            j >>= 1;
        }
    }
    for (int i = 1; i <= bd; i++)
    {
        cout << per[i].size() << " ";
        for (int j = 0; j < (int)per[i].size(); j++)
        {
            cout << per[i][j];
            if (j < (int)per[i].size() - 1)
                cout << " ";
        }
        cout << endl;
    }

    string s;
    cout.flush();
    cin >> s;
    int tot = 0;
    int mul = 1;
    for (auto c : s)
    {
        if (c == '1')
            tot += mul;
        mul <<= 1;
    }
    cout << tot + 1 << endl;
    return;
}
int main()
{
    solve();
    return 0;
}