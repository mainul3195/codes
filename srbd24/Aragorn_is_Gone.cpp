#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int countTeams(vector<int>& A) {
    int N = A.size();
    
    // dp[i][j] represents the number of ways to form a team with sum of energy levels
    // congruent to i modulo j, using any number of Orcs
    vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));
    
    // Base case: empty set
    dp[0][1] = 1;
    
    for (int i = 0; i < N; i++) {
        vector<vector<int>> new_dp = dp;
        for (int j = 1; j <= N; j++) {
            for (int k = 0; k < j; k++) {
                int new_k = (k + A[i]) % j;
                new_dp[new_k][j] = (new_dp[new_k][j] + dp[k][j]) % MOD;
            }
        }
        dp = new_dp;
    }
    
    // Sum up all valid teams (excluding empty set)
    int result = 0;
    for (int j = 1; j <= N; j++) {
        result = (result + dp[0][j]) % MOD;
    }
    
    return (result - 1 + MOD) % MOD; // Subtract 1 to exclude the empty set
}

int main() {
    int N;
    cin >> N;
    
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    cout << countTeams(A) << endl;
    
    return 0;
}