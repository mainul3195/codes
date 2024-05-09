#include<bits/stdc++.h>
using namespace std;
#define pi (2*acos(0.0))
#define eps 1e-9
void solve()
{
    double d, h, t;
    cin >> d >> h >> t; 
    t = t*pi/180.0;
    double r = d*tan(t);
    if(r-eps<h)
    {
        cout << fixed << setprecision(4) << pi*r*r << "\n";
        return;
    }
    cout << fixed << setprecision(4) << pi*r*r - (acos(h/r)*r*r - sqrt(r*r-h*h)*h) << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve(); 
    return 0;
}