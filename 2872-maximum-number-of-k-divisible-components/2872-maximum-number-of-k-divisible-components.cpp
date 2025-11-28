class Solution {
public:
    vector<vector<int>> adj;
    int k;
    int components;
    vector<int> vals;

    // Helper 1: Build adjacency list
    void buildGraph(int n, vector<vector<int>>& edges) {
        adj.assign(n, {});
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
    }

    // Helper 2: DFS to compute subtree sum and validate cuts
    long long dfs(int node, int parent) {
        long long sum = vals[node];

        for (int nei : adj[node]) {
            if (nei == parent) continue;
            sum += dfs(nei, node);
        }

        // If subtree sum divisible by k, this becomes a separate component
        if (sum % k == 0) {
            components++;
            return 0;  // cut here
        }
        return sum;   // pass sum upward
    }

    // Main function (required by LeetCode)
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int kVal) {

        k = kVal;
        vals = values;
        components = 0;

        buildGraph(n, edges);
        dfs(0, -1);

        return components;
    }
};
