#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[])
{
    registerGen(argc, argv, 1);
    int t = rnd.next(1, 100000);
    cout << t << "\n";
    for (int i = 0; i < t; i++)
    {
        int d = rnd.next(1, 1000000000);
        int h = rnd.next(1, 1000000000);
        int theta = rnd.next(0, 60);
        cout << d << " " << h << " " << theta << "\n";
    }
}
