#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> v[n];
    int frst = 0, scnd = 0;
    vector<int> middle_elements;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            int x;
            cin >> x;
            v[i].push_back(x);
        }
        if (k % 2 == 1)
            middle_elements.push_back(v[i][(k - 1) / 2]);
    }
    for (int j = 0; j < n; j++)
        for (int i = 0; i < v[j].size() / 2; i++)
            frst += v[j][i];
    for (int j = 0; j < n; j++)
        for (int i = (v[j].size() + 1) / 2; i < v[j].size(); i++)
            scnd += v[j][i];
    sort(middle_elements.rbegin(), middle_elements.rend());
    for (int i = 0; i < middle_elements.size(); i++)
    {
        if (i & 1)
            scnd += middle_elements[i];
        else
            frst += middle_elements[i];
    }
    cout << frst << " " << scnd << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}