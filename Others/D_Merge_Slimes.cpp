#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    set<pair<long long, long long>> st;
    for(int i = 0; i<n; i++)
    {
        long long s, c;
        cin >> s >> c;
        st.insert({s, c});
    }
    int count =0;
    while(st.size())
    {
        // cout << count << "\n";
        // for(auto [a, b]: st)
        //     cout << a << " " << b << "\n";
        auto [s, c] = *st.begin();
        st.erase(st.begin());
        if(c%2)
            count++;
        if(c/2>0)
        {
            long long nxt = s*2;
            auto it = st.lower_bound({nxt, -1});
            if(it!=st.end() && (*it).first == nxt)
            {
                c = (*it).second + c/2;
                st.erase(it);
                st.insert({nxt, c});
            }
            else
                st.insert({nxt, c/2});
        }
    }
    cout << count << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve(); 
    return 0;
}