#include <bits/stdc++.h>
using namespace std;
vector<long long> desired, actual;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    desired = vector<long long>(n);
    actual = vector<long long>(m);
    for (auto &i : desired)
        cin >> i;
    for (auto &i : actual)
        cin >> i;
    sort(desired.begin(), desired.end());
    sort(actual.begin(), actual.end());
    int i = 0, j = 0, count = 0;
    while (i < n && j < m)
    {
        if (actual[j] < desired[i] - k)
            j++;
        else if (actual[j] > desired[i] + k)
            i++;
        else
        {
            count++;
            i++;
            j++;
        }
    }
    cout << count << "\n";
    return 0;
}