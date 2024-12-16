#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long a, b;
    cin >> a >> b;
    if(b==2*a || b==2*a+1)
        cout << "Yes\n";
    else cout << "No\n";
    return 0;
}