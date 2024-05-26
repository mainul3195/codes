#include<bits/stdc++.h>
using namespace std;
long long nod[200005] = {0};
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n = 200005;
    memset(nod, 0, sizeof(nod));

    for(int i = 1; i<n; i++)
        for(int j = i; j<n; j+=i)
            nod[j]++;
    cin >> n;
        
    long long ans = 0;
    for(int i = 1; i<n; i++)
    {
        long long a = i;
        long long b  = n-i;
        ans += nod[a]*nod[b];
    }
    cout << ans << "\n";
    return 0;

}