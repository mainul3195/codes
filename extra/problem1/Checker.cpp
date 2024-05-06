#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

int n;
vector<long long> xx, yy, m;
long long X, Y, M;
inline void readAndCheckAnswer(InStream &in)
{
    long long Xa = in.readInt();
    long long Ya = in.readInt();
    long long Ma = in.readInt();
    if ((Xa != X) || (Ya != Y) || (Ma != M))
        in.quitf(_wa, "Wrong Answer");
}

int main(int argc, char *argv[])
{
    registerTestlibCmd(argc, argv);

    n = inf.readInt();
    m = vector<long long>(n);
    for (int i = 0; i < n; i++)
        m[i] = inf.readInt();
    for (int i = 0; i < n; i++)
    {
        int x, y;
        x = inf.readInt();
        y = inf.readInt();
        for (int j = 0; j < m[i]; j++)
            xx.push_back(x), yy.push_back(y);
    }
    X = xx[(xx.size() - 1) / 2];
    Y = yy[(yy.size() - 1) / 2];
    M = 0;
    for (int i = 0; i < xx.size(); i++)
        M += abs(xx[i]) + abs(yy[i]);
    // readAndCheckAnswer(ans);
    readAndCheckAnswer(ouf);

    quitf(_ok, "n=%d", n);
}