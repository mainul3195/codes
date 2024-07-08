#include <bits/stdc++.h>
using namespace std;
string p;

int priority(char x)
{
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    else
        return 0;
}

int main()
{
    int tc;
    cin >> tc;
    getline(cin, p);
    getline(cin, p);

    while (tc--)
    {
        string q;
        stack<char> s;
        while (getline(cin, p) && p.size())
        {
            char c = p[0];
            if (c == '(' || c == '{' || c == '[')
                s.push(c);
            else if (c == ')' || c == '}' || c == ']')
            {
                char open_bracket;
                if (c == ')')
                    open_bracket = '(';
                else if (c == '}')
                    open_bracket = '{';
                else
                    open_bracket = '[';

                while (!s.empty() && s.top() != open_bracket)
                {
                    q += s.top();
                    s.pop();
                }
                s.pop(); // Remove the matching opening bracket
            }
            else if (c == '+' || c == '-' || c == '*' || c == '/')
            {
                while (!s.empty() && priority(s.top()) >= priority(c))
                {
                    q += s.top();
                    s.pop();
                }
                s.push(c);
            }
            else
                q += c;
        }
        while (!s.empty())
        {
            q += s.top();
            s.pop();
        }
        cout << q << '\n';
        if(tc)
            cout << "\n";
    }
    return 0;
}