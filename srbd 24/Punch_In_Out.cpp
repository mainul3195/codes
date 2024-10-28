#include <iostream>
#include <string>
#include <vector>
using namespace std;

int tM(string t)
{
    int h = stoi(t.substr(0, 2));
    int m = stoi(t.substr(3, 2));
    return h * 60 + m;
}

double cW(vector<pair<char, string>> &p)
{
    int s = 0;
    int f = tM(p[0].second);
    bool k = (f > tM("11:00"));

    for (int i = 0; i < p.size(); i += 2)
    {
        int a = tM(p[i].second);
        int b = tM(p[i + 1].second);
        if (b == 0)
            b = 24 * 60;
        if (a < tM("07:00"))
            a = tM("07:00");
        if (k)
        {
            if (b <= tM("14:00"))
                continue;
            if (a < tM("14:00"))
                a = tM("14:00");
        }
        int d = b - a;
        if (a < tM("14:00") && b > tM("13:00"))
        {
            int ls = max(tM("13:00"), a);
            int le = min(tM("14:00"), b);
            if (le > ls)
                d -= (le - ls);
        }
        s += d;
    }

    return s / 60.0;
}

string dW(vector<pair<char, string>> &p)
{
    if (p.empty())
        return "Absent";
    int f = tM(p[0].second);
    if (f >= tM("15:00"))
        return "Absent";
    double w = cW(p);
    if (w < 4.0)
        return "Absent";
    string r;

    if (w >= 12.0)
    {
        r = "Overtime";
        return r;
    }

    if (f > tM("11:00"))
    {
        if (w >= 4.0)
        {
            r = "2nd Half";
            if (f > tM("14:30"))
            {
                r += " ~";
            }
        }
        else
        {
            return "Absent";
        }
    }
    else
    {
        if (w >= 8.0)
        {
            r = "Full Day";
        }
        else
        {
            r = "1st Half";
            if (f > tM("10:30"))
            {
                r += " ~";
            }
        }
    }

    return r;
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;

        vector<pair<char, string>> p(N);
        for (int i = 0; i < N; i++)
        {
            char d;
            string t;
            cin >> d >> t;
            p[i] = {d, t};
        }

        cout << dW(p) << endl;
    }

    return 0;
}
