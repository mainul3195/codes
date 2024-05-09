#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[])
{
    registerGen(argc, argv, 1);
    int n = rnd.next(1, 100000);
    cout << n << "\n";
    vector<int> m(n, 1);
    int tot = n;
    int final = rnd.next(n, 200000);
    while (tot < final)
    {
        int ind = rnd.next(0, n - 1);
        m[ind]++;
        tot++;
    }
    for (int i = 0; i < n; i++)
        cout << m[i] << " \n"[i == n - 1];
    for (int i = 0; i < n; i++)
    {
        int x = rnd.next(-1000000000, 1000000000);
        int y = rnd.next(-1000000000, 1000000000);
        cout << x << " " << y << "\n";
    }
}
