#include <bits/stdc++.h>
using namespace std;
int n, pos_one;
vector<int> positions;
bool Greater(int a, int b)
{
    cout << "? " << a << " " << pos_one << " " << b << "\n";
    cout.flush();
    string s;
    cin >> s;
    return (s == "Yes");
}
void Merge(int l, int m, int r)
{
    vector<int> tmp;
    int i = l, j = m + 1;
    while (i <= m || j <= r)
    {
        if (i == m + 1)
            tmp.push_back(positions[j++]);
        else if (j == r + 1)
            tmp.push_back(positions[i++]);
        else
        {
            if (Greater(positions[i], positions[j]))
                tmp.push_back(positions[j++]);
            else
                tmp.push_back(positions[i++]);
        }
    }
    i = 0;
    for (int j = l; j <= r; j++)
        positions[j] = tmp[i++];
    return;
}
void Sort(int l, int r)
{
    if (l >= r)
        return;
    int mid = (l + r) / 2;
    Sort(l, mid);
    Sort(mid + 1, r);
    Merge(l, mid, r);
    return;
}
void solve()
{
    cin >> n;
    pos_one = 1;
    for (int i = 2; i <= n; i++)
    {
        cout << "? " << i << " " << i << " " << pos_one << "\n";
        cout.flush();
        string s;
        cin >> s;
        if (s == "No")
            pos_one = i;
    }
    for (int i = 1; i <= n; i++)
        if (i != pos_one)
            positions.push_back(i);
    // cout << "yeay\n";
    Sort(0, positions.size() - 1);
    reverse(positions.begin(), positions.end());
    positions.push_back(pos_one);
    reverse(positions.begin(), positions.end());
    vector<int> permutation(n + 1);
    for (int i = 1; i <= n; i++)
        permutation[positions[i - 1]] = i;
    cout << "! ";
    for (int i = 1; i <= n; i++)
        cout << permutation[i] << " \n"[i == n];
    return;
}
int main()
{
    solve();
    return 0;
}