#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string a, b;
    cin >> a >> b;
    vector<int> na, nb;
    int num = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == '.')
        {
            na.push_back(num);
            num = 0;
            continue;
        }
        num = num * 10 + (a[i] - '0');
    }
    na.push_back(num);
    num = 0;
    for (int i = 0; i < b.size(); i++)
    {
        if (b[i] == '.')
        {
            nb.push_back(num);
            num = 0;
            continue;
        }
        num = num * 10 + (b[i] - '0');
    }
    nb.push_back(num);
    int i = 0;
    for (; i < na.size() && i < nb.size(); i++)
    {
        if (na[i] > nb[i])
        {
            cout << a << "\n";
            return;
        }
        if (nb[i] > na[i])
        {
            cout << b << "\n";
            return;
        }
    }
    if (a.size() > b.size())
        cout << a << "\n";
    else
        cout << b << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}