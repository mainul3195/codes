#include<bits/stdc++.h>
using namespace std;
bool prime(long long x)
{
    if(x==1)
        return false;
    if((x%2 == 0) && (x != 2))
        return false;
    for(long long i = 3; i*i <= x; i += 2)
    {
        if(x%i == 0)
            return false;
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        if((n==1) && (k==2))
        {
            cout << "YES\n";
            continue;
        }
        if(k>1)
        {
            cout << "NO\n";
            continue;
        }
        if(prime(n))
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}