#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int ans, mx =0;
        for(int i = 1; i<=n; i++)
        {
            int len, val;
            cin >> len >> val;
            if(len>10)
                continue;
            if(val>mx)
                ans = i, mx = val;
        }
        cout << ans << "\n";
    }
    return 0;
}