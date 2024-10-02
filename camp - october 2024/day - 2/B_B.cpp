#include<bits/stdc++.h>
using namespace std;
#define int long long
#define Mod 998244353
long long bigMod(long long b, long long p)
{
    if(!p) return 1;
    if(p&1) return (b*bigMod(b, p-1))%Mod;
    long long tmp = bigMod(b, p/2);
    return (tmp*tmp)%Mod;
}
long long modinv(long long n)
{
    return bigMod(n, Mod-2);
}
int n, q;
vector<long long>v;
struct nd{
    long long mul, add, div;
    bool lazy;
    nd(){
        add = lazy = 0;
        mul = div = 1;
    }
};
vector<nd> sg_tree;
void push_down(int l, int r, int node)
{
    if(l!=r)
    {
        int left = 2*node;
        int right = 2*node+1;
        (sg_tree[left].mul*=(sg_tree[node].div-1))%=Mod;
        (sg_tree[left].add = (sg_tree[left].add*(sg_tree[node].div-1)%Mod+sg_tree[node].add)%Mod);
        (sg_tree[left].div*=sg_tree[node].div)%=Mod;

        (sg_tree[right].mul*=(sg_tree[node].div-1))%=Mod;
        (sg_tree[right].add = (sg_tree[right].add*(sg_tree[node].div-1)%Mod+sg_tree[node].add)%Mod);
        (sg_tree[right].div*=sg_tree[node].div)%=Mod;

        sg_tree[left].lazy = sg_tree[right].lazy = 1;

        sg_tree[node].add = 0;
        sg_tree[node].div = 1;
        sg_tree[node].mul = 1;
    }
    sg_tree[node].lazy = 0;
    return;
}
void update(int l, int r, int value, int len, int node = 1, int start = 1, int end = n)
{
    if(start>r || end<l)
        return;
    if(sg_tree[node].lazy)
        push_down(start, end, node);
    if(start>=l && end<=r)
    {
        sg_tree[node].lazy = 1;
        (sg_tree[node].mul *= (len-1))%=Mod;
        (sg_tree[node].div *= len)%=Mod;
        sg_tree[node].add = (sg_tree[node].add*(len-1)%Mod+value+ Mod)%Mod;
        return;
    }
    int mid = (start+end)/2;
    update(l, r, value, len, 2*node, start, mid);
    update(l, r, value, len, 2*node+1, mid+1, end);
    return;
}
nd find(int ind, int node = 1, int start = 1, int end = n)
{
    if(sg_tree[node].lazy)
        push_down(start, end, node);
    if(start == end)
        return sg_tree[node];
    int mid = (start+end)/2;
    return (ind<=mid)? find(ind, 2*node, start, mid): find(ind, 2*node+1, mid+1, end);
}
void printTree()
{
    for(int i = 1; i<10; i++)
        cout << i << " -> " << sg_tree[i].mul << " " << sg_tree[i].add << " " << sg_tree[i].div << " " << sg_tree[i].lazy << "\n";
}
void solve()
{
    cin >> n >> q;
    v = vector<long long>(n+1);
    for(int i = 1; i<=n; i++)
        cin >> v[i];
    sg_tree = vector<nd>(4*n);
        // printTree();
        // cout << "\n\n";
    while(q--)
    {
        int l, r, val;
        cin >> l >> r >> val;
        // cout << l << " " << r << " " << val << "\n";
        update(l, r, val, r-l+1);
            // printTree();
            // cout << "\n\n";
    }
    for(int i = 1; i<=n; i++)
    { 
        nd x = find(i);
        cout << ((v[i]*x.mul%Mod+x.add + Mod)%Mod)*modinv(x.div)%Mod << " ";
        // cout << x.mul << " " << x.add << " " << x.div << " " << x.lazy << "\n";
    }
    cout << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve(); 
    return 0;
}