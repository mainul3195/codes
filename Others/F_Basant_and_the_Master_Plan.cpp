#include<bits/stdc++.h>
using namespace std;
string s = "1111111111";
vector<long long> valid;
vector<char> chars;
void check()
{
    long long i = 0;
    for(int j = 0; j<10; j++)
        i = i*10+s[j]-'0';
    // cout << i << "\n";
    long long num = i;
    int nod=0, cnt[3] = {0};

    while(i)
    {
        int r = i%10;
        i/=10;
        if(r == chars[0]-'0')
            cnt[0]++;
        else if(r==chars[1]-'0')
            cnt[1]++;
        else cnt[2]++;
        nod++;
    }
    nod--;
    if(nod)
    {
        //a check
        for(int j = 0; j<3; j++)
            if(cnt[j])
            {
                int sum = 0;
                for(int k = 0; k<3; k++)
                    sum += cnt[k]*(chars[k]-'0');
                sum -= (chars[j]-'0');
                if(sum%nod == 0 && sum/nod == chars[j]-'0')
                {
                    valid.push_back(num);
                    return;
                }
            }
    }
    return;
}
void okdone2(int i = 0, bool hasStarted = 0)
{
    if(i==10)
    {
        // cout << s << "\n";
        check();
        return;
    }
    if(!hasStarted)
    {
        s[i] = '0';
        okdone2(i+1, 0);
    }
    for(int j = 0; j<3; j++)
    {

        s[i] = chars[j];
        okdone2(i+1, 1);
    }
    return;
}
void okdone1(int i = 0)
{
    if(i==10)
    {
        // cout << s << "\n";
        check();
        return;
    }
    for(int j = 0; j<3; j++)
    {
        s[i] = chars[j];
        okdone1(i+1);
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    bool hasZero = 0;
    for(int i = 0; i<3; i++)
    {
        char c;
        cin >> c;
        chars.push_back(c);
        if(c=='0')
            hasZero = 1;
    }

    if(hasZero)
        okdone1();
    else okdone2();
    // s = "0000000123";
    // check();
    set<long long> st(valid.begin(), valid.end());
    valid = vector<long long>(st.begin(), st.end());
    int q;
    cin >> q;
    int mx =-1, ind = 1;
    for(int i =0; i<q; i++)
    {
        int l, r;
        cin >> l >> r;
        int x = upper_bound(valid.begin(), valid.end(), r) - lower_bound(valid.begin(), valid.end(), l);
        if(x>mx)
        {
            mx = x;
            ind = i+1;
        }
        // cout << i << " -> " << x << "\n";
    }
    // for(auto i: valid)
    //     cout << i << "\n";
    cout << ind << "\n";
    return 0;
}