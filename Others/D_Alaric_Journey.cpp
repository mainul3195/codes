#include <bits/stdc++.h>
using namespace std;

vector<long long> v;
void solve()
{
    int n;
    cin >> n;
    v = vector<long long>(n);
    for (auto &i : v)
        cin >> i;
    int op = 0;
    for (int i = 0, j = n - 1; i < j;)
    {
        if (v[i] != v[j])
        {
            if (v[i] < v[j])
            {
                v[i + 1] += v[i];
                i++;
            }
            else
            {
                v[j - 1] += v[j];
                j--;
            }
            op++;
        }
        else
            i++, j--;
    }
    cout << op << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}