#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        int cnt = 0;
        while(s.size())
        {
            while(s.back() == '0')
            {
                s.pop_back();
                cnt++;
            }
            s.pop_back();
            while(s.size())
            {
                if(s.back() != '0')
                    cnt++;
                s.pop_back();
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}