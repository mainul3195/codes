#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, t, a;
    cin >> n >> t >> a;
    int r = n - t - a;
    if (max(t, a) < min(t, a) + r)
        cout << "No\n";
    else
        cout << "Yes\n";

    return 0;
}