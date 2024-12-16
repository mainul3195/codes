#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;
        int p = 0, m = 0;
        for (auto c : s)
        {
            if (c == '+')
                p++;
            else
                m++;
        }
        cout << abs(p - m) << "\n";
    }
    return 0;
}