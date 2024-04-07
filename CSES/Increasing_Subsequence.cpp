#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n), lis;
    for (auto &i : v)
        cin >> i;
    for (auto i : v)
    {
        auto it = lower_bound(lis.begin(), lis.end(), i);
        if (it == lis.end())
            lis.push_back(i);
        else
            lis[it - lis.begin()] = i;
    }
    cout << lis.size() << "\n";
    return 0;
}