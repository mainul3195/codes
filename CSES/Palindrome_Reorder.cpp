#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int ar[26] = {0};
    for (auto c : s)
        ar[c - 'A']++;
    int odd_count = 0;
    int odd_ind;
    for (int i = 0; i < 26; i++)
        if (ar[i] % 2)
        {
            odd_count++;
            odd_ind = i;
        }
    if (odd_count > 1)
    {
        cout << "NO SOLUTION\n";
        return 0;
    }
    for (int i = 0; i < 26; i++)
        if (i != odd_ind)
        {
            int n = ar[i] / 2;
            while (n--)
                cout << (char)(i + 'A');
            ar[i] /= 2;
        }
    while (ar[odd_ind]--)
        cout << (char)(odd_ind + 'A');

    for (int i = 25; i >= 0; i--)
        if (i != odd_ind)
            while (ar[i]--)
                cout << (char)(i + 'A');
    cout << "\n";
    return 0;
}