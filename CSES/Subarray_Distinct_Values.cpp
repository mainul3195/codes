#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    map<int, int> taken;
    long long tot = 0, ini = 0;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
        taken[a]++;
        while (taken.size() > k)
        {
            taken[v[ini]]--;
            if (taken[v[ini]] == 0)
                taken.erase(taken.lower_bound(v[ini]));
            ini++;
        }
        tot += i - ini + 1;
    }
    cout << tot << "\n";
    return 0;
}