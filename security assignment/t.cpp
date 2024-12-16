#include <bits/stdc++.h>
using namespace std;
#define strt 'a'
#define nd 'z'
int main()
{
    // freopen("input.txt", "r", stdin);
    string mapping = "d:e g:t t:h m:a h:o i:b o:v e:r f:s s:n u:g x:d v:i b:u y:l c:p l:y q:c k:x j:w a:f z:m p:k ";
    stringstream s(mapping);
    string tmp;
    map<char, char> mp;
    map<char, bool> founda, foundb;
    while (s >> tmp)
    {
        char a = tmp[0];
        char b = tmp[2];
        if (founda.find(a) != founda.end())
        {
            cout << "The value of " << a << " has already been assigned.\n";
            return 0;
        }
        if (foundb.find(b) != foundb.end())
        {
            cout << "Character " << b << " has already been assigned!\n";
            return 0;
        }
        mp[a] = b;
        founda[a] = foundb[b] = 1;
    }
    string inp;
    int ar[26] = {0};
    while (getline(cin, inp))
    {
        for (auto c : inp)
        {
            if (c >= strt && c <= nd)
            {
                ar[c - strt]++;
                if (mp.find(c) == mp.end())
                    cout << "*";
                else
                    cout << mp[c];
            }
            else
                cout << c;
        }
        cout << "\n";
    }

    vector<pair<int, char>> v;
    for (int i = 0; i < 26; i++)
        v.push_back({ar[i], (char)(i + strt)});
    sort(v.rbegin(), v.rend());
    cout << "\n\n\n";
    cout << "Char\tfreq\tChar\tfreq\n";
    cout << "------------\t------------\n";
    for (int i = 0; i < 13; i++)
        cout << v[i].second << "\t" << v[i].first << "\t" << v[i + 13].second << "\t" << v[i + 13].first << "\n";

    return 0;
}
