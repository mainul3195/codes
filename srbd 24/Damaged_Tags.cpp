#include <bits/stdc++.h>
using namespace std;

class MatchingCounter {
private:
    // Adjacency list for each node in first set
    vector<vector<int>> adj = {
        {1, 2, 3},  // edges for 0
        {1, 4},     // edges for 1
        {1, 2, 5}   // edges for 2
    };
    
    int countMatches(int pos = 0, int used = 0) {
        // Base case: all elements from first set are matched
        if(pos == 3) return 1;
        
        int total = 0;
        
        // Try each possible edge from current position
        for(int next : adj[pos]) {
            // If this element from second set hasn't been used
            if(!(used & (1 << next))) {
                // Use it and move to next position
                total += countMatches(pos + 1, used | (1 << next));
            }
        }
        
        return total;
    }

public:
    int solve() {
        return countMatches();
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    MatchingCounter counter;
    cout << counter.solve() << "\n";
    
    return 0;
}