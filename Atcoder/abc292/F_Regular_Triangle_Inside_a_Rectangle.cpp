#include<bits/stdc++.h>
using namespace std;
#define eps 1e-13
#define pi (acos(-1.0))
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int a, b;
    cin >> a >> b;
    if(a>b)
        a^=b^=a^=b;
    // cout << a << " " << b << "\n";
    // cout << (2*a/tan(60*pi/180)) << "\n";
    if( (2*a/tan(60*pi/180)) - eps < b)
        cout << fixed << setprecision(9) << (2*a/tan(60*pi/180)) << "\n";
    else
    {
        double l = 0, r = 30;
        while(fabs(r-l)>1e-11)
        {
            double m1 = (l+(r-l)/3);
            double m2 = (l+(r-l)/3*2);
            // cout << m1 << " " << m2 << " ";
            double l1 = b/cos(m1*pi/180);
            double l2 = a/cos((90-(60+m1))*pi/180);
            double ans1 = min(l1, l2);

            l1 = b/cos(m2*pi/180);
            l2 = a/cos((90-(60+m2))*pi/180);
            double ans2 = min(l1, l2);
            // cout << ans1 << " " << ans2 << "\n";
            if(ans2 > ans1)
                l = m1;
            else
                r = m2;
        }
        // cout << l << " " << r << "\n";
        double l1 = b/cos(l*pi/180);
        double l2 = a/cos((90-(60+l))*pi/180);
        // cout << l1 << " " << l2 << "\n";
        double ans1 = min(l1, l2);
        cout << fixed << setprecision(9) << ans1 << "\n";
    }
    return 0;

}