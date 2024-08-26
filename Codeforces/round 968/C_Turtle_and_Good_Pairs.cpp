#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ar[26] = {0};
    for (auto c : s)
        ar[c - 'a']++;
    int done = 0;
    while (!done)
    {
        done = 1;
        for (int i = 0; i < 26; i++)
            if (ar[i])
            {
                done = 0;
                ar[i]--;
                cout << (char)(i + 'a');
            }
    }
    cout << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}