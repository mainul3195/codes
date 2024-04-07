#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        while (v.size() && v.back().first >= a)
            v.pop_back();
        if (!v.size())
            cout << "0 ";
        else
            cout << v.back().second << " ";
        v.push_back({a, i + 1});
    }
    return 0;
}