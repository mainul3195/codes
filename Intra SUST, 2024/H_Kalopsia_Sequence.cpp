#include<bits/stdc++.h>
using namespace std;
struct nd{
    int mn_pref, mx_pref, sum, lazy;
    nd()
    {
        mn_pref = mx_pref = sum = lazy = -1;
    }
};
int n, q;
vector<nd> seg_tree;
string s;
nd merge(nd a, nd b)
{
    nd c;
    c.sum = a.sum+b.sum;
    c.lazy = 0;
    c.mn_pref = min(a.mn_pref, a.sum+b.mn_pref);
    c.mx_pref = max(a.mx_pref, a.sum+b.mx_pref);
    return c;
}
void build(int node = 1, int start = 1, int end = n)
{
    if(start == end)
    {
        if(s[start-1] == '(')
            seg_tree[node].sum = 1;
        else seg_tree[node].sum = -1;
        seg_tree[node].lazy = 0;
        seg_tree[node].mn_pref = min(0, seg_tree[node].sum);
        seg_tree[node].mx_pref = max(0, seg_tree[node].sum);
        return;
    }
    int mid = (start+end)/2;
    build(2*node, start, mid);
    build(2*node+1, mid+1, end);
    seg_tree[node] = merge(seg_tree[2*node], seg_tree[2*node+1]);
    return;
}
void push_back(int node, int start, int end)
{
    seg_tree[node].lazy ^= 1;
    swap(seg_tree[node].mn_pref, seg_tree[node].mx_pref);
    seg_tree[node].sum *= -1;
    seg_tree[node].mn_pref *= -1;
    seg_tree[node].mx_pref *= -1;
    if(start != end)
    {
        seg_tree[2*node].lazy ^= 1;
        seg_tree[2*node+1].lazy ^= 1;
    }
    return;
}

void update(int l, int r, int node = 1, int start = 1, int end = n)
{
    if(seg_tree[node].lazy)
        push_back(node, start, end);
    if(start> r || end<l)
        return;
    if(start>=l && end<=r)
    {
        seg_tree[node].lazy ^= 1;
        if(seg_tree[node].lazy)
            push_back(node, start, end);
        return;
    }
    int mid = (start+end)/2;
    update(l, r, 2*node, start, mid);
    update(l, r, 2*node+1, mid+1, end);
    seg_tree[node] = merge(seg_tree[2*node], seg_tree[2*node+1]);
    return;
}

nd query(int l, int r, int node = 1, int start = 1, int end = n)
{
    if(seg_tree[node].lazy)
        push_back(node, start, end);
    if(start>=l && end<=r)
        return seg_tree[node];
    int mid = (start+end)/2;
    if(mid+1>r)
        return query(l, r, 2*node, start, mid);
    if(mid<l)
        return query(l, r, 2*node+1, mid+1, end);
    return merge(query(l, r, 2*node, start, mid), query(l, r, 2*node+1, mid+1, end));
}

void print_tree()
{
    for(int i = 1; i<=15; i++)
        cout << i << " -> :" << seg_tree[i].sum << " " << seg_tree[i].mn_pref << " " << seg_tree[i].mx_pref << " " << seg_tree[i].lazy << "\n";
    return;
}

void solve()
{
    cin >> n >> q;
    seg_tree = vector<nd>(4*n);
    cin >> s;
    build();
    // print_tree();
    // update(2,2);
    // cout << "\n";
    // print_tree();
    while(q--)
    {
        // print_tree();
        // cout << "\n";
        int t, l, r;
        cin >> t >> l >> r;
        if(t==1)
            update(l, r);
        else
        {
            nd tmp = query(l, r);
            if((tmp.mn_pref == 0)&&(tmp.sum == 0))
                cout << "YES\n";
            else cout << "NO\n";
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