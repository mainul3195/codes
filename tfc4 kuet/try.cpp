#include <bits/stdc++.h>
using namespace std;
struct nd
{
    long long mx, ind;
    bool operator<(const nd &a) const
    {
        return ind < a.ind;
    }
};
struct range
{
    int l, r, ind;
    long long ans;
    bool operator<(const range &a) const
    {
        return l < a.l || (l == a.l && r < a.r);
    }
};
int n, q;
vector<range> query;
vector<long long> x, c_sum;
vector<long long> bit;
void update(int ind, long long val)
{
    for (; ind <= n; ind += (ind & (-ind)))
        bit[ind] += val;
    return;
}
long long sum(int ind)
{
    long long ans = 0;
    for (; ind > 0; ind -= (ind & (-ind)))
        ans += bit[ind];
    return ans;
}
bool cmp(range &a, range &b)
{
    return a.ind < b.ind;
}
void solve()
{
    cin >> n >> q;
    x = vector<long long>(n + 1);
    bit = vector<long long>(n + 1, 0);
 
    c_sum = vector<long long>(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> x[i];
    for (int i = 1; i <= n; i++)
        c_sum[i] += c_sum[i - 1] + x[i];
    query = vector<range>(q);
    int count = 0;
    for (auto &[a, b, i, _] : query)
    {
        cin >> a >> b;
        i = count++;
    }
    sort(query.rbegin(), query.rend());
    int l, r;
    vector<nd> stack;
    vector<nd> pr;
    int last_done = n + 1;
    for (auto &[l, r, _, a] : query)
    {
        if (last_done > l)
        {
            int last = 0;
            for (int i = l; i < last_done; i++)
                if (x[i] > last)
                {
                    if (pr.size())
                    {
                        auto &[val, ind] = pr.back();
                        update(ind, (i - ind - 1) * val - c_sum[i - 1] + c_sum[ind] - sum(ind) + sum(ind - 1));
                    }
 
                    pr.push_back({x[i], i});
                    last = x[i];
                }
            last_done = l;
            while (stack.size() && stack.back().mx <= pr.back().mx)
            {
                update(stack.back().ind, -sum(stack.back().ind) + sum(stack.back().ind - 1));
                stack.pop_back();
            }
            if (stack.size())
                update(pr.back().ind, sum(pr.back().ind) - sum(pr.back().ind - 1) + (stack.back().ind - pr.back().ind - 1) * pr.back().mx - c_sum[stack.back().ind - 1] + c_sum[pr.back().ind]);
            while (pr.size())
            {
                stack.push_back(pr.back());
                pr.pop_back();
            }
        }
        auto it = upper_bound(stack.rbegin(), stack.rend(), (nd){-1, r});
        long long ans = 0;
        it--;
        ans = (r - (*it).ind) * (*it).mx - c_sum[r] + c_sum[(*it).ind];
        if (it - stack.rbegin() > 0)
        {
            it--;
            ans += sum((*it).ind);
        }
        a = ans;
    }
    sort(query.begin(), query.end(), cmp);
    for (auto [a, b, c, d] : query)
        cout << d << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}