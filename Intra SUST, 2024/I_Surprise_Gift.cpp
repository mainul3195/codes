#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    int v[n+1][n+1] = {0};
    for(int i = 1; i<=n; i++)
        for(int j = 1; j<=n; j++)
            v[i][j] = 1;
    if(__builtin_popcount(n) == 1)
    {
        for(int i = 1; i<=n; i++)
            for(int j = 1; j<=n; j++)
                cout << v[i][j] << " \n"[j==n];
        return 0;
    }
    else
    {
        int q = (1<<((int)log2(n+.5)+1))-n+1;
        v[1][1] = v[2][n-1] = v[3][n] = q;
        for(int i = 4; i<=n; i++)
            v[i][n-i+2] = q;
        if(n>4 && (n%2 == 0))
        {
            int c = n/2+1;
            v[c][2] = v[n][c] = q;
            v[c][c] = v[n][2] = 1;
        }
    }
    for(int i = 1; i<=n; i++)
        for(int j = 1; j<=n; j++)
            cout << v[i][j] << " \n"[j==n];
    return 0;
}