#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

int main(int argc, char *argv[])
{
    registerValidation(argc, argv);
    int t = inf.readInt(1, 100000, "T");
    for (int i = 0; i < t; i++)
    {
        inf.readInt(1, 1000000000, "D");
        inf.readSpace();
        inf.readInt(1, 1000000000, "H");
        inf.readSpace();
        inf.readInt(1, 1000000000, "theta");
        if (i != t - 1)
            inf.readEoln();
    }
    inf.readEof();
}