#include <bits/stdc++.h>
using namespace std;
vector<string> s(6), nw(6);
bool is_draw()
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            int cnt = 0;
            char c = s[i][j];
            for (int k = j; k < 7; k++)
            {
                if (s[i][k] == c)
                    cnt++;
                else
                    break;
                if (cnt == 4)
                    return 0;
            }
            cnt = 0;
            for (int k = i; k < 6; k++)
            {
                if (s[k][j] == c)
                    cnt++;
                else
                    break;
                if (cnt == 4)
                    return 0;
            }
            cnt = 0;
            for (int k = 0; k < 4 && i + k < 6 && j + k < 7; k++)
            {
                if (s[i + k][j + k] == c)
                    cnt++;
                else
                    break;
                if (cnt == 4)
                    return 0;
            }
            cnt = 0;
            for (int k = 0; k < 4 && i + k < 6 && j - k >= 0; k++)
            {
                if (s[i + k][j - k] == c)
                    cnt++;
                else
                    break;
                if (cnt == 4)
                    return 0;
            }
        }
    }
    return 1;
}
vector<int> khali;
long long c_f, c_l, f_f, f_l;
bool is_win(int i, int j)
{
    char ch = nw[i][j];
    int cnt = 0;
    for (int k = 0; k < 4 && j + k < 7; k++)
    {
        if (nw[i][j + k] == ch)
            cnt++;
        else
            break;
        if (cnt == 4)
            return 1;
    }
    cnt = 0;
    for (int k = 0; k < 4 && j - k >= 0; k++)
    {
        if (nw[i][j - k] == ch)
            cnt++;
        else
            break;
        if (cnt == 4)
            return 1;
    }
    cnt = 0;
    for (int k = 0; k < 4 && i + k < 6; k++)
    {
        if (nw[i + k][j] == ch)
            cnt++;
        else
            break;
        if (cnt == 4)
            return 1;
    }
    for (int k = 0; k < 4 && i + k < 6 && j + k < 7; k++)
    {
        if (nw[i + k][j + k] == ch)
            cnt++;
        else
            break;
        if (cnt == 4)
            return 1;
    }
    cnt = 0;
    for (int k = 0; k < 4 && j - k >= 0 && i + k < 6; k++)
    {
        if (nw[i + k][j - k] == ch)
            cnt++;
        else
            break;
        if (cnt == 4)
            return 1;
    }
    return 0;
}
void play(long long turn = 0)
{
    if (turn & 1)
    {
        for (int j = 0; j < 7; j++)
            if (khali[j] >= 0 && s[khali[j]][j] == 'F')
            {
                nw[khali[j]][j] = 'F';
                if (is_win(khali[j], j))
                {
                    f_f = min(f_f, turn);
                    f_l = max(f_l, turn);
                }
                else
                {
                    khali[j]--;
                    play(turn + 1);
                    khali[j]++;
                }
                nw[khali[j]][j] = '.';
            }
    }
    else
    {
        for (int j = 0; j < 7; j++)
            if (khali[j] >= 0 && s[khali[j]][j] == 'C')
            {
                nw[khali[j]][j] = 'C';
                if (is_win(khali[j], j))
                {
                    c_f = min(c_f, turn);
                    c_l = max(c_l, turn);
                }
                else
                {
                    khali[j]--;
                    play(turn + 1);
                    khali[j]++;
                }
                nw[khali[j]][j] = '.';
            }
    }
    return;
}
void solve()
{
    for (auto &i : s)
        cin >> i;
    // if (is_draw())
    // {
    //     cout << "0\n";
    //     return;
    // }
    khali = vector<int>(7, 5);
    c_f = f_f = LONG_LONG_MAX;
    c_l = f_l = LONG_LONG_MIN;
    for (auto &i : nw)
        for (auto &j : i)
            j = '.';
    play();
    cout << c_f << " " << c_l << " " << f_f << " " << f_l << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t, tc = 0;
    cin >> t;
    while (t--)
    {
        cout << "Case #" << ++tc << ": ";
        solve();
    }
    return 0;
}