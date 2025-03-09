#include <bits/stdc++.h>
using namespace std;
#define optimize()                \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define endl '\n'
int main()
{
    optimize();
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        vector<int> arr(n), pre(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (i > 0)
            {
                pre[i] = arr[i] + pre[i - 1];
            }
            else
            {
                pre[i] = arr[i];
            }
        }
        while (q--)
        {
            int l, r;
            cin >> l >> r;
            int sum;
            if (l > 0)
            {
                sum = pre[r] - pre[l - 1];
            }
            else
            {
                sum = pre[r];
            }
            cout << sum << endl;
        }
        if (t > 0)
        {
            cout << endl;
        }
    }

    return 0;
}
