#include <bits/stdc++.h>
using namespace std;
int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
map<string, int> mp;
void print_line()
{
    cout << "|---------------------------|\n";
    return;
}
void solve()
{
    int d, m, y;
    scanf("%d/%d/%d", &d, &m, &y);
    string s;
    cin >> s;
    int tot_days = days[m];
    if (m == 2)
    {
        if (y % 400 == 0 || (y % 100 != 0 && y % 4 == 0))
            tot_days++;
    }
    int start = ((mp[s] - (d - 1)) % 7 + 7) % 7;
    vector<vector<int>> cal(5, vector<int>(7, 0));
    int i = 0, j = start;
    for (int k = 1; k <= tot_days; k++)
    {
        cal[i][j] = k;
        j++;
        if (j == 7)
        {
            j = 0;
            i++;
        }
        if (i == 5)
            i = 0;
    }
    print_line();
    cout << "|Sun|Mon|Tue|Wed|Thu|Fri|Sat|\n";
    print_line();
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (!j)
                cout << "|";
            if (cal[i][j] == 0)
                cout << " - |";
            else
            {
                if (cal[i][j] > 9)
                    printf(" %d|", cal[i][j]);
                else
                    printf("  %d|", cal[i][j]);
            }
        }
        cout << "\n";
        print_line();
    }
    cout << "\n";

    return;
}
int main()
{
    // ios_base::sync_with_stdio(0); cin.tie(0);
    mp["Sun"] = 0;
    mp["Mon"] = 1;
    mp["Tue"] = 2;
    mp["Wed"] = 3;
    mp["Thu"] = 4;
    mp["Fri"] = 5;
    mp["Sat"] = 6;
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}