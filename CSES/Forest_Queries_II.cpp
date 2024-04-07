#include <bits/stdc++.h>
using namespace std;
int n, q;
vector<vector<long long>> grid, seg_tree;
void buildy(int nodex, int startx, int endx, int nodey = 1, int starty = 1, int endy = n)
{
    if (starty == endy)
    {
        if (startx == endx)
            seg_tree[nodex][nodey] = grid[startx][starty];
        else
            seg_tree[nodex][nodey] = seg_tree[2 * nodex][nodey] + seg_tree[2 * nodex + 1][nodey];
        return;
    }
    int mid = (starty + endy) / 2;
    buildy(nodex, startx, endx, 2 * nodey, starty, mid);
    buildy(nodex, startx, endx, 2 * nodey + 1, mid + 1, endy);
    seg_tree[nodex][nodey] = seg_tree[nodex][2 * nodey] + seg_tree[nodex][2 * nodey + 1];
    return;
}
void buildx(int nodex = 1, int startx = 1, int endx = n)
{
    if (startx != endx)
    {
        int mid = (startx + endx) / 2;
        buildx(2 * nodex, startx, mid);
        buildx(2 * nodex + 1, mid + 1, endx);
    }
    buildy(nodex, startx, endx);
}
void updatey(int r, int c, int nodex, int startx, int endx, int nodey = 1, int starty = 1, int endy = n)
{
    if (starty == endy)
    {
        if (startx == endx)
            seg_tree[nodex][nodey] ^= 1;
        else
            seg_tree[nodex][nodey] = seg_tree[2 * nodex][nodey] + seg_tree[2 * nodex + 1][nodey];
        return;
    }
    int mid = (starty + endy) / 2;
    c <= mid ? updatey(r, c, nodex, startx, endx, 2 * nodey, starty, mid) : updatey(r, c, nodex, startx, endx, 2 * nodey + 1, mid + 1, endy);
    seg_tree[nodex][nodey] = seg_tree[nodex][2 * nodey] + seg_tree[nodex][2 * nodey + 1];
    return;
}
void updatex(int r, int c, int nodex = 1, int startx = 1, int endx = n)
{
    if (startx != endx)
    {
        int mid = (startx + endx) / 2;
        if (r <= mid)
            updatex(r, c, 2 * nodex, startx, mid);
        else
            updatex(r, c, 2 * nodex + 1, mid + 1, endx);
    }
    updatey(r, c, nodex, startx, endx);
    return;
}
long long queryy(int c1, int c2, int nodex, int nodey = 1, int starty = 1, int endy = n)
{
    if (starty > c2 || endy < c1)
        return 0;
    if (starty >= c1 && endy <= c2)
        return seg_tree[nodex][nodey];
    int mid = (starty + endy) / 2;
    return queryy(c1, c2, nodex, 2 * nodey, starty, mid) + queryy(c1, c2, nodex, 2 * nodey + 1, mid + 1, endy);
}
long long query(int r1, int c1, int r2, int c2, int nodex = 1, int startx = 1, int endx = n)
{
    if (startx > r2 || endx < r1)
        return 0;
    if (startx >= r1 && endx <= r2)
        return queryy(c1, c2, nodex);
    int mid = (startx + endx) / 2;
    return query(r1, c1, r2, c2, 2 * nodex, startx, mid) + query(r1, c1, r2, c2, 2 * nodex + 1, mid + 1, endx);
}
void solve()
{
    cin >> n >> q;
    grid = vector<vector<long long>>(n + 1, vector<long long>(n + 1, 0));
    seg_tree = vector<vector<long long>>(4 * n, vector<long long>(4 * n, 0));
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++)
            if (s[j] == '*')
                grid[i + 1][j + 1] = 1;
    }
    buildx();
    while (q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int r, c;
            cin >> r >> c;
            updatex(r, c);
        }
        else
        {
            int r1, c1, r2, c2;
            cin >> r1 >> c1 >> r2 >> c2;
            cout << query(r1, c1, r2, c2) << "\n";
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