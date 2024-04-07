#include <bits/stdc++.h>
using namespace std;
void solve()
{
    long long n;
    cin >> n;
    long long sum = n * (n + 1) / 2;
    if (sum % 2)
    {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    set<long long> st;
    for (int i = 1; i <= n; i++)
        st.insert(i);
    long long need = sum / 2;
    vector<long long> v;
    long long tmp_sum = 0;
    for (int i = n; i >= 1; i--)
    {
        if (tmp_sum == need)
            break;
        if (tmp_sum + i <= need)
        {
            tmp_sum += i;
            v.push_back(i);
            st.erase(st.find(i));
        }
    }
    cout << st.size() << "\n";
    for (auto i : st)
        cout << i << " ";
    cout << "\n";
    cout << v.size() << "\n";
    for (auto i : v)
        cout << i << " ";
    cout << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}