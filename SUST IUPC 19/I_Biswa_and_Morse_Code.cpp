// #include <bits/stdc++.h>
// using namespace std;
// int calc(string s)
// {
//     int i = 0;
//     for (auto c : s)
//     {
//         if (c == '.')
//             i++;
//         else
//             i += 3;
//     }
//     return i + s.size() - 1;
// }
// void solve()
// {
//     string s;
//     while (cin >> s)
//     {
//         cout << "v.push_back({\""<< s << "\"," << calc(s) << "});\n";
//     }
//     return;
// }
// int main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     int t;
//     // cin >> t;
//     solve();
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
struct nd
{
    string s;
    int score;
    bool operator<(const nd &a) const
    {
        return score < a.score;
    }
};
vector<nd> v;
void solve()
{
    int n;
    cin >> n;
    string s;
    getline(cin, s);
    while (n--)
    {
        map<char, int> mp;
        getline(cin, s);
        for (auto c : s)
            if (c != ' ')
                mp[tolower(c)]++;
        vector<pair<int, char>> cnt;
        for (auto [a, c] : mp)
            cnt.push_back({c, a});
        sort(cnt.rbegin(), cnt.rend());
        map<char, string> ans;
        // cout << cnt.size() << " " << v.size() << "\n";
        for (int i = 0; i < 36; i++)
            ans[cnt[i].second] = v[i].s;
        for (char c = 'a'; c <= 'z'; c++)
            cout << ans[c] << "\n";
        for (char c = '0'; c <= '9'; c++)
            cout << ans[c] << "\n";
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    v.push_back({"-.-.", 11});
    v.push_back({".--.", 11});
    v.push_back({"....-", 11});
    v.push_back({"-..-", 11});
    v.push_back({".-", 5});
    v.push_back({".-.-", 11});
    v.push_back({"..--", 11});
    v.push_back({"---", 11});
    v.push_back({"-", 3});
    v.push_back({".....", 9});
    v.push_back({"-...", 9});
    v.push_back({".-..", 9});
    v.push_back({"..-.", 9});
    v.push_back({"--.", 9});
    v.push_back({".", 1});
    v.push_back({"...-", 9});
    v.push_back({"-.-", 9});
    v.push_back({".--", 9});
    v.push_back({"....", 7});
    v.push_back({"-..", 7});
    v.push_back({"..", 3});
    v.push_back({".-.", 7});
    v.push_back({"..-", 7});
    v.push_back({"--", 7});
    v.push_back({"...", 5});
    v.push_back({"-.", 5});
    v.push_back({"--.-", 13});
    v.push_back({"...--", 13});
    v.push_back({"-.--", 13});
    v.push_back({".---", 13});
    v.push_back({"......", 11});
    v.push_back({"-....", 11});
    v.push_back({".-...", 11});
    v.push_back({"..-..", 11});
    v.push_back({"--..", 11});
    v.push_back({"...-.", 11});
    sort(v.begin(), v.end());
    // for(auto [a, b]: v)
    //     cout << a << " " << b << "\n";
    solve();
    return 0;
}