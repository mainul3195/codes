
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (auto &i : a)
        cin >> i;
    for (auto &i : b)
        cin >> i;
    int found1 = -1;
    for (int i = 0; i < n; i++)
    {
        if (a[i])
        {
            if (found1 != -1)
            {
                cout << "No\n";
                return;
            }
            found1 = i;
            if (a[i] > m)
            {
                cout << "No\n";
                return;
            }
        }
    }
    if (found1 == -1)
    {
        cout << "No\n";
        return;
    }

    int found2 = -1;
    for (int i = 0; i < m; i++)
    {
        if (b[i])
        {
            if (found2 != -1)
            {
                cout << "No\n";
                return;
            }
            found2 = i;
            if (b[i] > n)
            {
                cout << "No\n";
                return;
            }
        }
    }
    if (found2 == -1)
    {
        cout << "No\n";
        return;
    }
    if ((a[found1] > 1 && b[found2] > 1))
    {
        cout << "No\n";
        return;
    }
    int ar[n][m];
    memset(ar, -1, sizeof(ar));
    int last = n * m;
    last--;
    ar[found1][found2] = 0;

    if (a[found1] > 1)
    {
        int mex = 1;
        for (int j = 0; j < m; j++)
            if (ar[found1][j] == -1)
            {
                ar[found1][j] = mex++;
                if (mex == a[found1])
                    break;
            }
        for (int j = 0; j < m; j++)
            if (ar[found1][j] == -1)
                ar[found1][j] = last--;
    }
    if (b[found2] > 1)
    {
        int mex = 1;
        for (int i = 0; i < n; i++)
            if (ar[i][found2] == -1)
            {
                ar[i][found2] = mex++;
                if (mex == b[found2])
                    break;
            }
        for (int i = 0; i < n; i++)
            if (ar[i][found2] == -1)
                ar[i][found2] = last--;
    }
    for (int j = 0; j < m; j++)
        if (ar[found1][j] == -1)
            ar[found1][j] = last--;
    for (int i = 0; i < n; i++)
        if (ar[i][found2] == -1)
            ar[i][found2] = last--;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (ar[i][j] == -1)
                ar[i][j] = last--;
    set<int> st;
    for (int j = 0; j < m; j++)
        st.insert(ar[found1][j]);
    int mex = 0;
    for (auto i : st)
    {
        if (i != mex)
            break;
        mex++;
    }
    if (mex != a[found1])
    {
        cout << "No\n";
        return;
    }
    st.clear();
    for (int i = 0; i < n; i++)
        st.insert(ar[i][found2]);
    mex = 0;
    for (auto i : st)
    {
        if (i != mex)
            break;
        mex++;
    }
    if (mex != b[found2])
    {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cout << ar[i][j] << " \n"[j == m - 1];

    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}