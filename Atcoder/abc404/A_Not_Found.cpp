#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int ar[26] = {0};
    for(auto c: s)
        ar[c-'a']++;
    for(int i = 0; i<26; i++)
        if(!ar[i])
        {
            cout << (char)(i+'a') << "\n";
            return 0;
        }
        return 0;
}