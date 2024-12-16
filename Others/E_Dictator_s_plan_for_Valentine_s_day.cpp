#include<bits/stdc++.h>
using namespace std;
#define int long long
#define MAX 200005

int parent[MAX];

void make_set(int v)
{
    parent[v]=v;
}

int find_set(int v)
{
    if(parent[v]==v)
        return v;
    return parent[v]=find_set(parent[v]);
}

void init()
{
    for(int i=0; i<MAX; i++)
        make_set(i);
}
struct Data{
    long long l,r,c;
};
vector<Data> query;
long long color[MAX];
int n, m;
struct nd{
    long long l, r, x;
    bool operator<(const nd &a)const
    {
        return x<a.x;
    }
};
vector<long long> Time;
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> m >> n;
    memset(color, -1, sizeof(color));
    vector<nd>guards(m);
    for(auto &[l, r, x]: guards)
    {
        cin >> l >> r >> x;
        l-=x;
        r-=x;
    }
    sort(guards.begin(), guards.end());
    Time = vector<long long>(n);
    for(auto &i: Time)
        cin >> i;
    for(int i = m-1; i>=0; i--)
    {
        int l = lower_bound(Time.begin(), Time.end(), guards[i].l) - Time.begin();
        int r = lower_bound(Time.begin(), Time.end(), guards[i].r) - Time.begin()-1;
        if(l<=r)
            query.push_back({l, r, guards[i].x});
    }
    reverse(query.begin(), query.end());
    init();
    for(auto [l, r, c]: query)
        for(int v=find_set(l); v<=r; v=find_set(v))
        {
            color[v]=c;
            parent[v]=v+1;
        }
    for(int i=0; i<n; i++)
        cout<<color[i]<< "\n";
    return 0;
}