#include <bits/stdc++.h>
using namespace std;
map<int, int> num_freq;
void solve()
{
    int n;
    cin >> n;
    num_freq.clear();
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++, sum += i)
            num_freq[sum]++;
    }
    int mx_freq = 0;
    for (auto [num, freq] : num_freq)
        if (freq != (2 * n - 1))
            mx_freq = max(mx_freq, freq);
    vector<vector<int>> frequency_occured_numbers(mx_freq + 1);
    for (auto [num, freq] : num_freq)
        if (freq != (2 * n - 1))
            frequency_occured_numbers[freq].push_back(num);

    int lim = (n - 1) * (n - 1);
    for (int i = 0; i <= lim; i++)
    {
        num_freq[i];
        // cout << i << " -> " << num_freq[i] << "\n";
    }
    // cout << "\n";

    map<string, int> str_cnt;
    map<char, int> single_char;
    lim = n * n;
    for (int i = 0; i < lim; i++)
    {
        string s;
        cin >> s;
        if (s.size() == 1)
            single_char[s[0]]++;
        else
            str_cnt[s]++;
    }
    map<char, vector<pair<char, int>>> surute, seshe;
    for (auto [s, f] : str_cnt)
    {
        surute[s[0]].push_back({s[1], f});
        seshe[s[1]].push_back({s[0], f});
    }
    map<int, char> int_to_char;
    map<char, int> char_to_int;
    int int_found[100] = {0};
    for (auto [c, f] : single_char)
    {
        if (f == 1)
        {
            int_to_char[1] = c;
            char_to_int[c] = 1;
            int_found[1] = 1;
        }
        else if (f == 2 * n - 1)
        {
            int_to_char[0] = c;
            char_to_int[c] = 0;
            int_found[0] = 1;
        }
    }
    // for (auto [i, c] : int_to_char)
    //     cout << i << " -> " << c << "\n";
    // cout << "\n";

    char ch = int_to_char[1];

    int found_count = 2;
    int loop_count = 0;
    while (found_count < n)
    {
        loop_count++;
        int cur_found = found_count;
        for (int i = 0; i < n; i++)
            if (int_found[i])
            {
                char ch = int_to_char[i];
                // surute
                if (i)
                {
                    // cout << ch << " ok \n";
                    map<int, int> freq_of_freq;
                    for (auto [c, f] : surute[ch])
                        freq_of_freq[f]++;
                    // for (auto [c, f] : surute[ch])
                    //     cout << c << " -> " << f << "\n";
                    // if (i == 2)
                    // {
                    //     cout << " Here\n";
                    //     return;
                    // }
                    char target_char = 0;
                    int target_frequncy = -1;
                    for (auto [c, f] : surute[ch])
                        if (freq_of_freq[f] == 1 && char_to_int.find(c) == char_to_int.end())
                        {
                            target_char = c;
                            target_frequncy = f;

                            for (auto num : frequency_occured_numbers[target_frequncy])
                                if (num / n == i && num_freq[num] == target_frequncy)
                                {
                                    // cout << target_char << " here = " << target_frequncy << "\n";
                                    int target_value = num % n;
                                    // cout << "target value -> " << target_value << "\t" << num << "\n";
                                    int_to_char[target_value] = target_char;
                                    char_to_int[target_char] = target_value;
                                    found_count++;
                                    int_found[target_value] = 1;

                                    break;
                                }
                            if (found_count == n)
                                break;
                        }
                }
                if (found_count == n)
                    break;
                // seshe
                map<int, int> freq_of_freq;
                for (auto [c, f] : seshe[ch])
                    freq_of_freq[f]++;
                char target_char = 0;
                int target_frequncy = -1;
                for (auto [c, f] : seshe[ch])
                    if (freq_of_freq[f] == 1 && char_to_int.find(c) == char_to_int.end())
                    {
                        target_char = c;
                        target_frequncy = f;

                        for (auto num : frequency_occured_numbers[target_frequncy])
                            if (num % n == i && num_freq[num] == target_frequncy)
                            {
                                // cout << target_char << " here = " << target_frequncy << "\n";
                                int target_value = num / n;
                                // cout << "target value -> " << target_value << "\t" << num << "\n";
                                int_to_char[target_value] = target_char;
                                char_to_int[target_char] = target_value;
                                found_count++;
                                int_found[target_value] = 1;
                                break;
                            }
                        if (found_count == n)
                            break;
                    }
                if (found_count == n)
                    break;
            }
        if (found_count == n - 1)
        {
            char target_char = 0;
            for (auto [c, f] : single_char)
            {
                if (char_to_int.find(c) == char_to_int.end())
                {
                    target_char = c;
                    break;
                }
            }
            int target_value;
            for (int i = 0; i < n; i++)
                if (!int_found[i])
                {
                    target_value = i;
                    break;
                }
            int_to_char[target_value] = target_char;
            char_to_int[target_char] = target_value;
            found_count++;
            int_found[target_value] = 1;
        }
        // cout << "After loop:\n";
        // for (auto [i, c] : int_to_char)
        //     cout << i << " -> " << c << "\n";
        // cout << "\n";
        if (loop_count == 5)
        {
            return;
        }
        // if (cur_found == found_count)
        //     assert(0);
    }
    for (auto [i, c] : int_to_char)
        cout << c;
    cout << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, tc = 0;
    cin >> t;
    while (t--)
    {
        // cout << "Case " << ++tc << ": ";
        solve();
    }
    return 0;
}