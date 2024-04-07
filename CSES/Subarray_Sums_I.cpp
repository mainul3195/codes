#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    vector<long long> v(n);
    for (auto &i : v)
        cin >> i;
    int sum = v[0], i = 0, j = 0, count = 0;
    while (j < n && i < n)
    {
        if (sum < x)
        {
            j++;
            if (j < n)
                sum += v[j];
        }
        else
        {
            if(sum == x)
                count++;
            sum-=v[i++];
        }
    }
    cout << count << "\n";
    return 0;
}