#include <bits/stdc++.h>
using namespace std;
int grundy[50];
int calc_grundy(int i)
{
    if (~grundy[i])
        return grundy[i];
    set<int> st;
    st.insert(calc_grundy(max(0, i - 1)));
    st.insert(calc_grundy(max(0, i - 2)));
    st.insert(0);
    int mex = 0;
    for (auto i : st)
    {
        if (i != mex)
            break;
        mex++;
    }
    return grundy[i] = mex;
}
void solve()
{
    memset(grundy, -1, sizeof(grundy));
    grundy[0] = 1;
    int ar[26] = {0};
    string s;
    cin >> s;
    for (auto c : s)
        ar[c - 'A']++;
    int X = 0;
    for (int i = 0; i < 26; i++)
        if (ar[i])
            X ^= calc_grundy(ar[i]);
    if (X)
        cout << "Alice\n";
    else
        cout << "Bob\n";

    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}