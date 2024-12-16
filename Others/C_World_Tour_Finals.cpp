#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(m), score(n, 0);
    for(auto &i: v)
        cin >> i;
    int mx_score = 0;
    vector<vector<int>>not_solved(n);
    for(int i = 0; i<n; i++)
    {
        string s;
        cin >> s;
        for(int j = 0; j<m; j++)
        {
            if(s[j] == 'o')
                score[i]+=v[j];
            else not_solved[i].push_back(v[j]);
        }
        score[i]+=(i+1);
        mx_score = max(mx_score, score[i]);
    }
    for(auto &ar: not_solved)
        sort(ar.rbegin(), ar.rend());
    // cout << mx_score << "\n";
    for(int i = 0; i<n; i++)
    {
        if(score[i] == mx_score)
        {
            cout << "0\n";
        }
        else
        {
            int count = 0, ind = 0;
            while(score[i]<=mx_score)
            {
                count++;
                score[i]+=not_solved[i][ind++];
            }
            cout << count << "\n";
        }
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve(); 
    return 0;
}