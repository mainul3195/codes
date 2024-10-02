#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    deque<int> dq;
    bool frnt = 1;
    while(n--)
    {
        string s;
        cin >> s;
        if(s=="toFront")
        {
            int x;
            cin >> x;
            if(frnt)
                dq.push_front(x);
            else dq.push_back(x);
        }
        else if(s=="front")
        {
            if(dq.empty())
            {
                cout << "No job for Ada?\n";
                continue;
            }
            if(frnt)
            {
                cout << dq.front() << "\n";
                dq.pop_front();
            }
            else
            {
                cout << dq.back() << "\n";
                dq.pop_back();
            }
        }
        else if(s=="back")
        {
            if(dq.empty())
            {
                cout << "No job for Ada?\n";
                continue;
            }
            if(!frnt)
            {
                cout << dq.front() << "\n";
                dq.pop_front();
            }
            else
            {
                cout << dq.back() << "\n";
                dq.pop_back();
            }
        }
        else if(s=="reverse")
            frnt = !frnt;
        else if(s=="push_back")
        {
            int x;
            cin >> x;
            if(!frnt)
                dq.push_front(x);
            else dq.push_back(x);
        }
    }
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve(); 
    return 0;
}