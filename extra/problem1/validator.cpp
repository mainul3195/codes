#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

int main(int argc, char *argv[])
{
    registerValidation(argc, argv);
    int n = inf.readInt(1, 100000, "n");
    inf.readEoln();
    long long sum_m = 0;
    for (int i = 0; i < n; i++)
    {
        int m = inf.readInt(1, 100000, "m");
        sum_m += m;
        if (i < n - 1)
            inf.readSpace();
    }
    ensuref(sum_m <= 200000, "Sum of mi does not exceed 200000");
    inf.readEoln();
    for (int i = 0; i < n; i++)
    {
        int u = inf.readInt(-1000000000, 1000000000, "x");
        inf.readSpace();
        int v = inf.readInt(-1000000000, 1000000000, "y");
        inf.readEoln();
    }
    inf.readEof();
}