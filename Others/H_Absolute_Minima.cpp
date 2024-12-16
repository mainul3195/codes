#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int q;
    cin >> q;
    long long con = 0;
    priority_queue<long long> lower;
    priority_queue<long long, vector<long long>, greater<long long>> upper;
    long long lower_sum = 0, upper_sum = 0;
    while (q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            long long a, b;
            cin >> a >> b;
            con += b;
            if (!lower.size() || !upper.size() || (a <= upper.top()))
            {
                lower.push(a);
                lower_sum += a;
            }
            else
            {
                upper.push(a);
                upper_sum += a;
            }
            if (lower.size() >= upper.size() + 2)
            {
                lower_sum -= lower.top();
                upper_sum += lower.top();
                upper.push(lower.top());
                lower.pop();
            }
            if (upper.size() > lower.size())
            {
                upper_sum -= upper.top();
                lower_sum += upper.top();
                lower.push(upper.top());
                upper.pop();
            }
        }
        else
        {
            long long x = lower.top();
            long long f = x * lower.size() - lower_sum + upper_sum - x * upper.size();
            cout << x << " " << f + con << "\n";
        }
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}