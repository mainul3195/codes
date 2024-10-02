#include<bits/stdc++.h>
using namespace std;
#define b_size 550
#define max 100005
struct query{
    int l, r, id;
};
query Q[1000006];
int ar[max], ans[1000006], frequency[100005], cnt = 0;
bool cmp(query &a, query &b)
{
    if((a.l/b_size) != (b.l/b_size))
        return a.l<b.l;
    return ((a.l/b_size)%2)?a.r>b.r:a.r<b.r;
}
void add(int pos)
{
    frequency[ar[pos]]++;
    if(frequency[ar[pos]]%2==0)
        cnt++;
}
void sub(int pos)
{
    frequency[ar[pos]]--;
    if((frequency[ar[pos]]%2==1))
        cnt--;
}
void mo(int q)
{
    sort(Q, Q+q, cmp);
        
    int cur_l = 0, cur_r = -1;
    for(int i =0; i<q; i++)
    {
        int L = Q[i].l;
        int R = Q[i].r;

        while(cur_l>L)
            add(--cur_l);
            //             for(int i = 1; i<=3; i++)
            // cout << "freq " << i << " -> " << frequency[i] << "\n";
        while(cur_r<R)
            add(++cur_r);
        // cout << "here => " << cnt << "\n";
        // for(int i = 1; i<=3; i++)
        //     cout << "freq " << i << " -> " << frequency[i] << "\n";
        while(cur_l<L)
            sub(cur_l++);
        while(cur_r>R)
            sub(cur_r--);
        ans[Q[i].id] = cnt;
//         cout << cur_l << " " << cur_r << ": ";
// cout << Q[i].id << " " << Q[i].l << " " << Q[i].r << " " << cnt << "\n";

    }
    for(int i = 0; i<q; i++)
        cout << ans[i] << "\n";
}
void solve()
{
    int i, j, n, q, L, R;
    cin >> n;
    for(int i = 0; i<n; i++)
        cin >> ar[i];
    cin >> q;
    for(int i = 0; i<q; i++)
    {
        cin >> L >> R;
        Q[i].id = i;
        Q[i].l = L-1;
        Q[i].r = R-1;
    }
    mo(q);
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve(); 
    return 0;
}