#include <bits/stdc++.h>
using namespace std;
vector<vector<long long>> key_matrix;
vector<vector<long long>> generate_key_matrix(string key)
{
    int n = sqrt(key.size() + .5);
    vector<vector<long long>> ans(n, vector<long long>(n));
    int k = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            ans[i][j] = (key[k++] - 'A');
    return ans;
}
string encrypt(string msg, string key)
{
    string enc = "";
    int n = key_matrix.size();
    vector<long long> row_matrix(n);
    for (int i = 0; i < n; i++)
        row_matrix[i] = msg[i] - 'A';
    for (int i = 0; i < n; i++)
    {
        long long sum = 0;
        for (int j = 0; j < n; j++)
            sum += row_matrix[j] * key_matrix[i][j];
        sum %= 26;
        enc += (sum + 'A');
    }
    return enc;
}
vector<vector<long long>> co_efficient(vector<vector<long long>> v, int r, int c)
{
    int n = v.size();
    vector<vector<long long>> ans(n - 1, vector<long long>(n - 1));
    int k = 0, l = 0, d = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (i == r || j == c)
                continue;
            ans[k][l] = v[i][j];
            l++;
            if (l == n - 1)
            {
                k++;
                l = 0;
            }
        }
    return ans;
}
long long determinant(vector<vector<long long>> v)
{
    int n = v.size();
    if (n == 1)
        return v[0][0];
    long long det = 0, sign = 1;
    for (int i = 0; i < n; i++)
    {
        det += sign * v[0][i] * determinant(co_efficient(v, 0, i));
        sign *= -1;
    }
    return det;
}
vector<vector<long long>> transpose(vector<vector<long long>> v)
{
    int n = v.size();
    vector<vector<long long>> ans(n, vector<long long>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            ans[j][i] = v[i][j];
    return ans;
}
vector<vector<long long>> co_efficient_matrix(vector<vector<long long>> v)
{
    int n = v.size();
    vector<vector<long long>> ans(n, vector<long long>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            ans[i][j] = ((i + j) % 2 ? -1 : 1) * determinant(co_efficient(v, i, j));
    return ans;
}
// vector<vector<long long>> inverse;
// void find_inverse(vector<vector<long long>> v)
// {
//     long long det = determinant(v);
//     cout << det
// }
int main()
{

    string msg = "SUSTCSE";
    string key = "AWESOMEINTRODUCTIONTOCOMPUTERSECURITYANDFORENSICS";
    key_matrix = generate_key_matrix(key);
    for (auto a : key_matrix)
    {
        for (auto b : a)
            cout << b << " ";
        cout << "\n";
    }
    cout << determinant(key_matrix) << "\n";
    string enc = encrypt(msg, key);
    cout << "Encrypted message: " << enc << endl;

    return 0;
}
