#include <bits/stdc++.h>
using namespace std;
const int N = 1000006;
const double eps = 1e-9;
#define endl '\n'

//    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
//    jkunu code feel korte hole templet copy kora jabe nah(contest chara)
double c;
double pred(double h)
{
    double ans = (1.00 / 3.00);
    ans = ans * c * c * h;
    ans /= ((4 * h * h) + (2 * 1.00 * c));
    return ans;
}

int32_t main()
{

    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (1)
    {
        cin >> c;
        if (c < 0.0)
            break;
        double high = 10;
        double low = 0;
        double ans = 0;
        int op = 60;
        while (op--)
        {
            double mid = (high - low) / 3.00;
            double m1 = low + mid;
            double m2 = high - mid;
            double mm1 = pred(m1);
            double mm2 = pred(m2);
            // cout << mm1 << " mm1 mm2 " << mm2 << endl ;
            if (mm1 - mm2 >= eps)
            {
                ans = max(ans, mm1);
                high = m2 - eps;
            }
            else if (mm2 - mm1 >= eps)
            {
                ans = max(mm2, ans);
                low = m1 + eps;
            }
            else
            {
                high = m2 - eps;
                low = m1 + eps;
                ans = max(ans, mm1);
            }
        }

        cout << fixed << setprecision(9) << ans << endl;
    }

    return 0;
}