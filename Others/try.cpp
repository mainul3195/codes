#include <bits/stdc++.h>
using namespace std;
struct nd
{
    int train_no, next_station, start_time, end_time, fair;
};
struct pq_node
{
    int cost, arrival_time, station_id, train_no;
    bool operator<(const pq_node &a) const
    {
        return cost > a.cost;
    }
};
struct node_info
{
    int arrival_time, cost, train_no, previous_station, departure_time_of_previous_station;
    bool operator<(const node_info &a) const
    {
        return arrival_time < a.arrival_time || (arrival_time == a.arrival_time && cost < a.cost);
    }
};
struct last_info
{
    int train_no, starting_station, next_station, starting_time, end_time, fair;
};
vector<vector<nd>> adj(21);
int find_min_cost(int start = 1, int end = 4)
{
    priority_queue<pq_node> q;
    q.push({0, 0, start, -1});
    vector<set<node_info>> dis(21);
    dis[start].insert({0, 0, -1, -1, -1});
    while (q.size())
    {
        auto [cost, arrival_time, u, Train_No] = q.top();
        q.pop();
        for (auto [train_no, next_station, start_time, end_time, fair] : adj[u])
        {
            if (start_time < arrival_time)
                continue;
            int tmp_cost = cost + fair;
            auto it = dis[next_station].upper_bound({end_time, -1, -1, -1, -1});
            vector<node_info> v;
            for (; it != dis[next_station].end(); it++)
                if ((*it).cost >= tmp_cost)
                    v.push_back((*it));
            for (auto x : v)
                dis[next_station].erase(dis[next_station].find(x));
            dis[next_station].insert({end_time, tmp_cost, train_no, u, start_time});
            q.push({tmp_cost, end_time, next_station, train_no});
        }
    }
    int mn_cost = 1000000000;
    last_info temporary;
    for (auto [arrival_time, cost, train_no, prev_station, departure_of_prev_station] : dis[end])
    {
        if (cost < mn_cost)
        {
            mn_cost = cost;
            temporary = {train_no, prev_station, end, departure_of_prev_station, arrival_time, 0};
        }
    }
    vector<last_info> v;
    v.push_back(temporary);
    int cur_s = temporary.starting_station;
    int cur_t = temporary.starting_time;
    while (cur_s != -1)
    {
        for (auto [arrival_time, cost, train_no, prev_station, departure_of_prev_station] : dis[cur])
        {
            if (cost < mn_cost)
            {
                mn_cost = cost;
                temporary = {train_no, prev_station, end, departure_of_prev_station, arrival_time, 0};
            }
        }
    }
    return mn_cost;
}
void solve()
{
    int train_no, start_station, next_station, start_time, end_time, fair;
    string st, et;
    while (cin >> train_no >> start_station >> next_station >> st >> et >> fair)
    {
        start_time = end_time = 0;
        int cur = 0;
        for (auto c : st)
        {
            if (c == ':')
            {
                start_time += 60 * cur;
                cur = 0;
            }
            else
                cur = cur * 10 + (c - '0');
        }
        start_time += cur;
        cur = 0;
        for (auto c : et)
        {
            if (c == ':')
            {
                end_time += 60 * cur;
                cur = 0;
            }
            else
                cur = cur * 10 + (c - '0');
        }
        end_time += cur;
        adj[start_station].push_back({train_no, next_station, start_time, end_time, fair});
    }
    // for (int i = 1; i <= 4; i++)
    // {
    //     for (auto [a, b, c, d, e] : adj[i])
    //     {
    //         cout << i << " -> " << a << " " << b << " " << c << " " << d << " " << e << "\n";
    //     }
    // }
    cout << find_min_cost() << "\n";
    return;
}
int main()
{
    solve();
    return 0;
}