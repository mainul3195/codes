#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    set<int> st;
    while (n--)
    {
        int x;
        cin >> x;
        st.insert(x);
    }
    cout << st.size() << "\n";
    return 0;
}