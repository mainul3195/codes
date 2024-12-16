#include <bits/stdc++.h>
using namespace std;

vector<vector<long long>> v = {{1, 0, 2, -1},
                               {3, 0, 0, 5},
                               {2, 1, 4, -3},
                               {1, 0, 5, 0}};

int main()
{
    vector<vector<long long>> tmp = co_efficient_matrix(v);
    for (auto a : tmp)
    {
        for (auto b : a)
            cout << b << " ";
        cout << "\n";
    }
    return 0;
}