#include <bits/stdc++.h>
using namespace std;
vector<int> make_lexicographically_smallest(vector<int> &arr)
{
    int n = arr.size();

    // Create graph representation
    vector<vector<int>> graph(n);
    vector<int> in_degree(n, 0);

    // Build graph based on lexicographic constraints
    for (int i = 0; i < n; i++)
    {
        // Connect current element to next if it needs reduction
        int next_idx = (i + 1) % n;
        if (arr[i] > arr[next_idx])
        {
            graph[i].push_back(next_idx);
            in_degree[next_idx]++;
        }
    }

    // Topological sort with lexicographic minimization
    vector<int> result = arr;

    // Priority queue to ensure lexicographically smallest order
    priority_queue<int, vector<int>, greater<int>> queue;
    for (int i = 0; i < n; i++)
    {
        if (in_degree[i] == 0)
        {
            queue.push(i);
        }
    }

    int processed = 0;
    while (!queue.empty())
    {
        int curr = queue.top();
        queue.pop();

        // Increment and move if needed
        int next_idx = (curr + 1) % n;
        if (next_idx < curr && result[curr] > result[next_idx])
        {
            result[curr]++;
            // Rotate the array
            rotate(result.begin(), result.begin() + curr + 1, result.end());
        }

        // Process neighbors
        for (int next_node : graph[curr])
        {
            in_degree[next_node]--;
            if (in_degree[next_node] == 0)
            {
                queue.push(next_node);
            }
        }

        processed++;
        if (processed >= n)
            break;
    }

    return result;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> result = make_lexicographically_smallest(arr);

    // Print result
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve();

    return 0;
}