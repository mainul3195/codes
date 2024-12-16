#include <bits/stdc++.h>
using namespace std;
struct minions
{
    int id, pos_x, pos_y, health, speed;
    bool operator<(const minions &a) const
    {
        return id < a.id;
    }
};
struct object
{
    string type;
    int id, owner, position_x, position_y, health, damage, range, cooldown, bounty;
};
vector<string> initial_grid;
vector<object> obj;
vector<vector<int>> min_dist, temporary_grid, prediction_grid, cum_sum, masking_grid;
minions mine[5], opponent[5];
int my_money, opponent_money, my_score, opponent_score, player_id, width, height, busy[5], next_to_check = 0;
void pre_values();
void input_status();
void print_spawn_pos();
void protect();
void attack();
void forward();
void make_prediction_grid();
void plan_bomb(int);
void manage_unmask(int);
void clear_to_bomb(int);
int main()
{
    pre_values();
    for (int _ = 0; _ < 200; _++)
    {
        input_status();
        if (_)
        {
            clear_to_bomb(_);
            manage_unmask(_);
            make_prediction_grid();
            protect();
            attack();
            plan_bomb(_);
            forward();
        }
        else
            print_spawn_pos();
    }
    return 0;
}

struct attack_box
{
    int sum, id, xl, yl, xr, yr;
    bool operator<(const attack_box &a) const
    {
        return sum > a.sum;
    }
};
struct no_name
{
    int id, x, y, xl, yl, xr, yr;
};
vector<no_name> to_bomb;
void mask(int xl, int yl, int xr, int yr)
{
    for (int i = yl; i <= yr; i++)
        for (int j = xl; j <= xr; j++)
            masking_grid[i][j]--;
    return;
}
void unmask(int xl, int yl, int xr, int yr)
{
    for (int i = yl; i <= yr; i++)
        for (int j = xl; j <= xr; j++)
            masking_grid[i][j]++;
    return;
}
struct box
{
    int xl, yl, xr, yr;
};
vector<vector<box>> to_unmask(205);
void manage_unmask(int turn)
{
    if (to_unmask[turn].size())
        unmask(to_unmask[turn][0].xl, to_unmask[turn][0].yl, to_unmask[turn][0].xr, to_unmask[turn][0].yr);
    to_unmask[turn].clear();
    return;
}
void clear_to_bomb(int turn)
{
    if (to_bomb.empty())
        return;
    reverse(to_bomb.begin(), to_bomb.end());
    while (to_bomb.size())
    {
        if (my_money >= 100)
        {
            if (abs(mine[to_bomb[0].id].pos_x - to_bomb[0].x) > 3 || abs(mine[to_bomb[0].id].pos_y - to_bomb[0].y) > 3)
            {
                to_bomb.pop_back();
                continue;
            }
            my_money -= 100;
            cout << "build " << to_bomb.back().id << " BOMB " << to_bomb.back().x << " " << to_bomb.back().y << endl;
            busy[to_bomb.back().id] = 1;
            mask(to_bomb[0].xl, to_bomb[0].yl, to_bomb[0].xr, to_bomb[0].yr);
            to_unmask[turn + 3].push_back({to_bomb[0].xl, to_bomb[0].yl, to_bomb[0].xr, to_bomb[0].yr});
        }
        to_bomb.pop_back();
    }
    to_bomb.clear();
    return;
}
int get_sum(int xl, int yl, int xr, int yr)
{
    if (xl >= 0 && yl >= 0 && xr >= 0 && yr >= 0 && xl < width && xr < width && yl < height && yr < height)
    {
        int sm = cum_sum[yr][xr];
        if (xl > 0)
            sm -= cum_sum[yr][xl - 1];
        if (yl > 0)
            sm -= cum_sum[yl - 1][xr];
        if (xl > 0 && yl > 0)
            sm += cum_sum[yl - 1][xl - 1];
        return sm;
    }
    return 0;
}
int opponent_count(attack_box a)
{
    int cnt = 0;
    for (int i = 0; i < 5; i++)
    {
        if (opponent[i].pos_x >= a.xl && opponent[i].pos_x <= a.xr && opponent[i].pos_y >= a.yl && opponent[i].pos_y <= a.yr)
            cnt++;
    }
    return cnt;
}
int player_in_the_box()
{
    int tot = 0;
    if (player_id == 0)
    {
        for (int i = 0; i < 5; i++)
            if (opponent[i].pos_x >= 0 && opponent[i].pos_x <= 4 && opponent[i].pos_y >= 5 && opponent[i].pos_y <= 9 && min_dist[opponent[i].pos_y][opponent[i].pos_x] > 1)
                tot++;
    }
    else
    {
        for (int i = 0; i < 5; i++)
            if (opponent[i].pos_x >= 15 && opponent[i].pos_x <= 19 && opponent[i].pos_y >= 5 && opponent[i].pos_y <= 9 && min_dist[opponent[i].pos_y][opponent[i].pos_x] > 1)
                tot++;
    }
    return tot;
}
void plan_bomb(int turn)
{
    vector<attack_box> v;
    if (player_id == 0)
    {
        cerr << "Here we go" << endl;
        int standing;
        for (int i = 0; i < 5; i++)
            if (mine[i].pos_x == 0 && mine[i].pos_y == 6)
            {
                standing = i;
                break;
            }
        if (turn >= next_to_check)
            if (busy[standing] == 0)
            {
                if (player_in_the_box() >= 2)
                {
                    if (my_money >= 200)
                    {
                        cerr << "Here" << endl;
                        cout << "build " << standing << " BOMB " << 2 << " " << 7 << endl;
                        my_money -= 100;
                        to_bomb.push_back({standing, 2, 7, 0, 5, 4, 9});
                        next_to_check = turn + 4;
                        busy[standing] = 1;
                    }
                }
            }
        if (busy[standing] == 0)
            cout << "attack " << standing << " EAST" << endl, busy[standing] = 1;
        for (int i = 0; i < 5; i++)
            if (!busy[i])
                for (int xl = mine[i].pos_x, yl = mine[i].pos_y - 3, xr = mine[i].pos_x + 3, yr = mine[i].pos_y; yl <= mine[i].pos_y; yl++, yr++)
                    v.push_back({get_sum(xl, yl, xr, yr), i, xl, yl, xr, yr});
        sort(v.begin(), v.end());
        if (v.size())
        {
            if (opponent_count(v[0]) < 2)
            {
                reverse(v.begin(), v.end());
                v.pop_back();
                reverse(v.begin(), v.end());
            }
        }
        if (v.size())
        {
            cerr << v[0].id << " x = " << v[0].xl << " y = " << v[0].yl << " sum = " << v[0].sum << " oc = " << opponent_count(v[0]) << "\n";
        }
        if (v.size() && v[0].sum >= 3 && opponent_count(v[0]) >= 3)
        {
            int x = v[0].xl + 1, y = v[0].yl + 1;
            if (my_money >= 200)
            {
                cout << "build " << v[0].id << " BOMB " << x << " " << y << endl;
                my_money -= 100;
                busy[v[0].id] = 1;
                to_bomb.push_back({v[0].id, x, y + 1, v[0].xl, v[0].yl, v[0].xr, v[0].yr});
            }
        }
    }
    else
    {
        int standing;
        for (int i = 0; i < 5; i++)
            if (mine[i].pos_x == 19 && mine[i].pos_y == 6)
            {
                standing = i;
                break;
            }
        if (turn >= next_to_check)
            if (busy[standing] == 0)
            {
                bool done = 0;
                if (player_in_the_box() >= 2)
                {
                    if (my_money >= 200)
                    {
                        cout << "build " << standing << " BOMB " << 17 << " " << 7 << endl;
                        my_money -= 100;
                        to_bomb.push_back({standing, 17, 7, 15, 5, 19, 9});
                        next_to_check = turn + 4;
                        busy[standing] = 1;
                    }
                }
            }
        if (busy[standing] == 0)
            cout << "attack " << standing << " WEST" << endl, busy[standing] = 1;
        for (int i = 0; i < 5; i++)
            if (!busy[i])
                for (int xl = mine[i].pos_x - 3, yl = mine[i].pos_y - 3, xr = mine[i].pos_x, yr = mine[i].pos_y; yl <= mine[i].pos_y; yl++, yr++)
                    v.push_back({get_sum(xl, yl, xr, yr), i, xl, yl, xr, yr});
        sort(v.begin(), v.end());
        if (v.size())
        {
            if (opponent_count(v[0]) < 2)
            {
                reverse(v.begin(), v.end());
                v.pop_back();
                reverse(v.begin(), v.end());
            }
        }
        if (v.size() && v[0].sum >= 3 && opponent_count(v[0]) >= 3)
        {
            int x = v[0].xl + 2, y = v[0].yl + 1;
            if (my_money >= 200)
            {
                cout << "build " << v[0].id << " BOMB " << x << " " << y << endl;
                my_money -= 100;
                busy[v[0].id] = 1;
                to_bomb.push_back({v[0].id, x, y + 1, v[0].xl, v[0].yl, v[0].xr, v[0].yr});
            }
        }
    }
    return;
}

bool valid(int x, int y)
{
    return x >= 0 && y >= 0 && x < width && y < height && initial_grid[y][x] == '.' && temporary_grid[y][x] == 0;
}

void calculate_min_dist()
{
    min_dist = vector<vector<int>>(height + 1, vector<int>(width + 1, 2000000000));
    temporary_grid = vector<vector<int>>(height + 1, vector<int>(width + 1, 0));
    for (auto [type, id, owner, pos_x, pos_y, a, b, c, d, e] : obj)
    {
        if (type == "WALL" || type == "GUN_TOWER" || type == "STUN_TOWER")
            temporary_grid[pos_y][pos_x] = 1;
    }
    queue<pair<int, int>> q;
    if (player_id)
    {
        q.push({19, 7});
        min_dist[7][19] = 0;
    }
    else
    {
        q.push({0, 7});
        min_dist[7][0] = 0;
    }
    int X[] = {1, 0, -1, 0}, Y[] = {0, 1, 0, -1};
    while (q.size())
    {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + X[i];
            int ny = y + Y[i];
            if (valid(nx, ny) && min_dist[ny][nx] == 2000000000)
            {
                min_dist[ny][nx] = min_dist[y][x] + 1;
                q.push({nx, ny});
            }
        }
    }
    return;
}
void make_prediction_grid()
{
    calculate_min_dist();
    vector<pair<int, int>> cur, next1, next2;
    for (int i = 0; i < 5; i++)
        cur.push_back({opponent[i].pos_x, opponent[i].pos_y});
    int X[] = {1, 0, -1, 0}, Y[] = {0, 1, 0, -1};
    for (auto [x, y] : cur)
    {
        if (masking_grid[y][x] <= 0)
            continue;
        int mn_cost = 2000000000;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + X[i];
            int ny = y + Y[i];
            if (valid(nx, ny) && min_dist[ny][nx] < mn_cost)
                mn_cost = min_dist[ny][nx];
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = x + X[i];
            int ny = y + Y[i];
            if (valid(nx, ny) && min_dist[ny][nx] == mn_cost)
                next1.push_back({nx, ny});
        }
    }
    for (auto [x, y] : next1)
    {
        if (masking_grid[y][x] <= 0)
            continue;
        int mn_cost = 2000000000;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + X[i];
            int ny = y + Y[i];
            if (valid(nx, ny) && min_dist[ny][nx] < mn_cost)
                mn_cost = min_dist[ny][nx];
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = x + X[i];
            int ny = y + Y[i];
            if (valid(nx, ny) && min_dist[ny][nx] == mn_cost)
                next2.push_back({nx, ny});
        }
    }
    prediction_grid = cum_sum = vector<vector<int>>(height + 1, vector<int>(width + 1, 0));
    for (auto [x, y] : next2)
        prediction_grid[y][x] += 1;
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            if (masking_grid[i][j] <= 0)
                prediction_grid[i][j] = 0;
    for (int i = 0; i < height; i++)
        cum_sum[i][0] = prediction_grid[i][0];
    for (int i = 0; i < width; i++)
        cum_sum[0][i] = prediction_grid[0][i];
    for (int i = 1; i < height; i++)
        for (int j = 1; j < width; j++)
            cum_sum[i][j] = cum_sum[i - 1][j] + cum_sum[i][j - 1] - cum_sum[i - 1][j - 1] + prediction_grid[i][j];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
            cerr << prediction_grid[i][j] << " ";
        cerr << endl;
    }
}

void pre_values()
{
    cin >> player_id;
    cin.ignore();
    cin >> width >> height;
    cin.ignore();
    for (int i = 0; i < height; i++)
    {
        string line;
        getline(cin, line);
        initial_grid.push_back(line);
    }
    masking_grid = vector<vector<int>>(height + 1, vector<int>(width + 1, 1));
    for (auto s : initial_grid)
        cerr << s << endl;
    return;
}
void forward()
{
    for (int i = 0; i < 5; i++)
        if (!busy[i])
            cout << "go " << i << endl;
    return;
}
void attack()
{
    if (player_id)
    {
        for (auto [type, id, owner, pos_x, pos_y, a, b, c, d, e] : obj)
            if (owner == 0 && type != "FIREBOMB")
                for (int i = 0; i < 5; i++)
                    if (!busy[i])
                    {
                        if (mine[i].pos_y == pos_y && mine[i].pos_x - 1 == pos_x)
                        {
                            cout << "attack " << i << " WEST"
                                 << endl;
                            cerr << i << " -> " << type << endl;
                            busy[i] = 1;
                            return;
                        }
                        if (mine[i].pos_x == pos_x && mine[i].pos_y + 1 == pos_y)
                        {
                            cout << "attack " << i << " SOUTH"
                                 << endl;
                            cerr << i << " -> " << type << endl;
                            busy[i] = 1;
                            return;
                        }
                        if (mine[i].pos_x == pos_x && mine[i].pos_y - 1 == pos_y)
                        {
                            cout << "attack " << i << " NORTH"
                                 << endl;
                            cerr << i << " -> " << type << endl;
                            busy[i] = 1;
                            return;
                        }
                    }
    }
    else
    {
        for (auto [type, id, owner, pos_x, pos_y, a, b, c, d, e] : obj)
            if (owner == 1 && type != "FIREBOMB")
                for (int i = 0; i < 5; i++)
                    if (!busy[i])
                    {
                        if (mine[i].pos_y == pos_y && mine[i].pos_x + 1 == pos_x)
                        {
                            cout << "attack " << i << " EAST"
                                 << endl;
                            cerr << i << " -> " << type << endl;
                            busy[i] = 1;
                            return;
                        }
                        if (mine[i].pos_x == pos_x && mine[i].pos_y + 1 == pos_y)
                        {
                            cout << "attack " << i << " SOUTH"
                                 << endl;
                            cerr << i << " -> " << type << endl;
                            busy[i] = 1;
                            return;
                        }
                        if (mine[i].pos_x == pos_x && mine[i].pos_y - 1 == pos_y)
                        {
                            cout << "attack " << i << " NORTH"
                                 << endl;
                            cerr << i << " -> " << type << endl;
                            busy[i] = 1;
                            return;
                        }
                    }
    }
    return;
}

void protect()
{
    if (my_money < 40)
        return;
    if (player_id)
    {
        for (auto [type, id, owner, pos_x, pos_y, a, b, c, d, e] : obj)
        {
            if (owner && type == "WALL" && pos_x == 19 && pos_y == 7)
                return;
        }
        bool ok = 1;
        for (int i = 0; i <= 5; i++)
            if (mine[i].pos_x == 19 && mine[i].pos_y == 7)
            {
                ok = 0;
                break;
            }
        if (ok)
        {
            for (int i = 0; i < 5; i++)
                if (!busy[i])
                {
                    if ((mine[i].pos_x == 19 && mine[i].pos_y == 6) ||
                        (mine[i].pos_x == 19 && mine[i].pos_y == 8) ||
                        (mine[i].pos_x == 18 && mine[i].pos_y == 7))
                    {
                        cout << "build " << i << " WALL 19 7"
                             << endl;
                        busy[i] = 1;
                        my_money -= 40;
                        return;
                    }
                }
        }
    }
    else
    {
        for (auto [type, id, owner, pos_x, pos_y, a, b, c, d, e] : obj)
        {
            if (owner == 0 && type == "WALL" && pos_x == 0 && pos_y == 7)
                return;
        }
        bool ok = 1;
        for (int i = 0; i <= 5; i++)
            if (mine[i].pos_x == 0 && mine[i].pos_y == 7)
            {
                ok = 0;
                break;
            }
        if (ok)
        {
            for (int i = 0; i < 5; i++)
                if (!busy[i])
                {
                    if ((mine[i].pos_x == 0 && mine[i].pos_y == 6) ||
                        (mine[i].pos_x == 0 && mine[i].pos_y == 8) ||
                        (mine[i].pos_x == 1 && mine[i].pos_y == 7))
                    {
                        cout << "build " << i << " WALL 0 7"
                             << endl;
                        busy[i] = 1;
                        my_money -= 40;
                        return;
                    }
                }
        }
    }
    return;
}

void input_status()
{
    cin >> my_money >> opponent_money;
    cin.ignore();
    cin >> my_score >> opponent_score;
    cin.ignore();

    for (auto &[a, b, c, d, e] : mine)
    {
        cin >> a >> b >> c >> d >> e;
        cin.ignore();
    }
    for (auto &[a, b, c, d, e] : opponent)
    {
        cin >> a >> b >> c >> d >> e;
        cin.ignore();
    }
    int obj_count;
    cin >> obj_count;
    cin.ignore();
    obj = vector<object>(obj_count);
    for (auto &[type, id, owner, position_x, position_y, health, damage, range, cooldown, bounty] : obj)
    {
        cin >> type >> id >> owner >> position_x >> position_y >> health >> damage >> range >> cooldown >> bounty;
        cin.ignore();
    }
    sort(mine, mine + 5);
    sort(opponent, opponent + 5);
    memset(busy, 0, sizeof(busy));
    return;
}

struct pnode
{
    int dis, x, y;
    bool operator<(const pnode &a) const
    {
        return dis > a.dis;
    }
};
int find_min_distance(int xi, int yi, int xf, int yf)
{
    vector<vector<int>> dis(height, vector<int>(width, 2000000000));
    dis[yi][xi] = 0;
    priority_queue<pnode> q;
    q.push({0, xi, yi});
    int X[] = {1, 0, -1, 0}, Y[] = {0, 1, 0, -1};
    while (q.size())
    {
        auto [d, x, y] = q.top();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + X[i];
            int ny = y + Y[i];
            if (nx >= 0 && ny >= 0 && nx < width && ny < height && initial_grid[ny][nx] == '.' && dis[ny][nx] > dis[y][x] + 1)
            {
                dis[ny][nx] = dis[y][x] + 1;
                q.push({dis[ny][nx], nx, ny});
            }
        }
    }
    return dis[yf][xf];
}
void print_spawn_pos()
{
    vector<pair<int, int>> v;
    if (player_id)
    {
        for (int i = 0; i < height; i++)
            v.push_back({find_min_distance(19, i, 0, 7), i});
    }
    else
    {
        for (int i = 0; i < height; i++)
            v.push_back({find_min_distance(0, i, 19, 7), i});
    }
    sort(v.begin(), v.end());
    set<int> st;
    st.insert(6);
    for (int i = 0; i < 10; i++)
    {
        if (v[i].second == 7)
            continue;
        st.insert(v[i].second);
        if (st.size() == 5)
            break;
    }
    for (auto i : st)
        cout << i << endl;
    return;
}

/**
 * Output only after all the input has been proceessed.
 * Input has been processed for you.
 * On first turn (After taking the input) you must output 5 itegers on 5 line.
 * Starting from second turn you must output one of thise 3 command for each of your 5 minions.
 * => go character_id
 * => build character_id object position_x position_y
 * => attack character_id direction
 * **Debug using you the stderr.
 * **You should flush the stdout in each turn
 **/