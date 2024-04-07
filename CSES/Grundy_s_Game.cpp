#include <bits/stdc++.h>
using namespace std;
int grundy[1000006];
int mex(vector<int> &v)
{
    int i = 0;
    set<int> st(v.begin(), v.end());
    while (st.size() && *st.begin() == i)
    {
        st.erase(st.begin());
        i++;
    }
    return i;
}
int find_grundy(int n)
{
    if (~grundy[n])
        return grundy[n];
    int x = 0, lim = (n + 1) / 2;
    vector<int> v;
    for (int i = 1; i < lim; i++)
        v.push_back(find_grundy(i) ^ find_grundy(n - i));
    return grundy[n] = mex(v);
}
void solve()
{
    int n;
    cin >> n;
    if (find_grundy(n))
        cout << "first\n";
    else
        cout << "second\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << "HEre\n";
    memset(grundy, -1, sizeof(grundy));
    grundy[0] = grundy[1] = grundy[2] = 0;
    find_grundy(1000);
    for (int i = 0; i <= 100; i++)
        cout << grundy[i] << "\n";
    // int t;
    // cin >> t;
    // while (t--)
    //     solve();
    return 0;
}