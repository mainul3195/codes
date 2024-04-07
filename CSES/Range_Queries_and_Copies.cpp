#include <bits/stdc++.h>
using namespace std;
struct node
{
    long long sum;
    node *left, *right;
    node(int val)
    {
        sum = val;
        left = right = NULL;
    }
    node(node *a, node *b)
    {
        sum = a->sum + b->sum;
        left = a;
        right = b;
    }
    node(node *a)
    {
        sum = a->sum;
        left = a->left;
        right = a->right;
    }
};
int n, q;
vector<node> roots;
vector<int> v;
node *build(int start = 0, int end = n - 1)
{
    if (start == end)
        return new node(v[start]);
    return new node(build(start, (start + end) / 2), build((start + end) / 2 + 1, end));
}
long long query(node nd, int l, int r, int start = 0, int end = n - 1)
{
    if (start > r || end < l)
        return 0;
    if (start >= l && end <= r)
        return nd.sum;
    int mid = (start + end) / 2;
    return query(*nd.left, l, r, start, mid) + query(*nd.right, l, r, mid + 1, end);
}
node *update(node *nd, int ind, int val, int start = 0, int end = n - 1)
{
    if (start == end)
        return new node(val);
    int mid = (start + end) / 2;
    return (ind <= mid ? new node(update(nd->left, ind, val, start, mid), nd->right) : new node(nd->left, update(nd->right, ind, val, mid + 1, end)));
}
void print_tree(node nd)
{
    queue<node> q;
    q.push(nd);
    while (q.size())
    {
        node u = q.front();
        cout << u.sum << " ";
        q.pop();
        if (u.left != NULL)
        {
            q.push(*u.left);
            q.push(*u.right);
        }
    }
    cout << "\n";
    return;
}
void solve()
{
    cin >> n >> q;
    v = vector<int>(n);
    for (auto &i : v)
        cin >> i;
    roots.push_back(*build());
    while (q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int k, ind, val;
            cin >> k >> ind >> val;
            k--, ind--;
            node *nw = update(&roots[k], ind, val);
            roots[k] = *nw;
        }
        else if (t == 2)
        {
            int l, r, k;
            cin >> k >> l >> r;
            l--, r--, k--;
            cout << query(roots[k], l, r) << "\n";
        }
        else
        {
            int k;
            cin >> k;
            k--;
            roots.push_back(*(new node(roots[k])));
        }
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}