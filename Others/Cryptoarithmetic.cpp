#include<bits/stdc++.h>
using namespace std;
vector<string> left_variables = {"TWO", "TWO"}, right_varibles = {"FOUR"};
// vector<string> left_variables = {"SEND", "MORE"}, right_varibles = {"MONEY"};
// vector<string> left_variables = {"TO", "GO"}, right_varibles = {"OUT"};
// vector<string> left_variables = {"MOSES", "MEETS"}, right_varibles = {"SALOME"};
// vector<string> left_variables = {"EAT", "THAT"}, right_varibles = {"APPLE"};
set<char> st;
vector<char>all_chars, firsts;
vector<int> assignment(26);
vector<vector<int>>valid_Assignments;
vector<bool> taken(10);

bool valid_assignment()
{
    for(auto c: firsts)
        if(assignment[c-'A'] == 0)
            return 0;
    int sum = 0;
    for(auto s: left_variables)
    {
        int num =0;
        for(auto c: s)
            num = num*10+assignment[c-'A'];
        sum += num;
    }
    // cout << sum << "\n";
    string s = right_varibles[0];
    while(s.size())
    {
        if(assignment[s.back()-'A']!=sum%10)
            return 0;
        s.pop_back();
        sum/=10;
    }
    if(sum)
        return 0;
    return 1;
}

void Assign(int j = 0)
{
    // cout << j << "\n";
    if(j == all_chars.size())
    {
        if(valid_assignment())
        {
            valid_Assignments.push_back(assignment);
        }
        return;
    }
    for(int i = 0; i<10; i++)
        if(!taken[i])
        {
            taken[i] = 1;
            assignment[all_chars[j]-'A'] = i;
            Assign(j+1);
            taken[i] = 0;
        }
    return;
}
int main()
{
    for(auto s: left_variables)
        for(auto c: s)
            st.insert(c);
    for(auto s: right_varibles)
        for(auto c: s)
            st.insert(c);
    all_chars = vector<char>(st.begin(), st.end());
    for(int i = 0; i<left_variables.size(); i++)
        firsts.push_back(left_variables[i][0]);
    for(int i = 0; i<right_varibles.size(); i++)
        firsts.push_back(right_varibles[i][0]);
    // for(auto c: all_chars)
    //     cout << c << "\n";
    Assign();
    // assignment['T'-'A'] = 7;
    // assignment['W'-'A'] = 6;
    // assignment['O'-'A'] = 5;
    // assignment['F'-'A'] = 1;
    // assignment['U'-'A'] = 3;
    // assignment['R'-'A'] = 0;
    // cout << valid_assignment() << "\n";
    int ans_count = 0;
    cout << "Answer for \"";
    for(int i = 0; i<left_variables.size(); i++)
    {
        if(i)
            cout << "+ ";
        cout << left_variables[i] << " ";
    }
    cout << "= ";
    for(int i = 0; i<right_varibles.size(); i++)
    {
        if(i)
            cout << "+ ";
        cout << right_varibles[i];
        if(i!=right_varibles.size()-1)
            cout << " ";
    }
    cout << "\"\n--------------------------------\n";
    for(auto v: valid_Assignments)
    {
        cout << "Answer " << ++ans_count << ": ";
        bool frst = 1;
        for(auto s: left_variables)
        {
            if(frst)
                frst = 0;
            else cout << "+ ";
            for(auto c: s)
                cout << v[c-'A'];
            cout << " ";
        }
        cout << "= ";
        for(auto s: right_varibles)
        {
            for(auto c: s)
                cout << v[c-'A'];
            cout << " ";
        }
        cout << "\n";
        cout << "Assignments:\n";
        for(auto c: all_chars)
            cout << "\'" << c << "\' -> " << assignment[c-'A'] << "\n";
    }
    return 0;
}