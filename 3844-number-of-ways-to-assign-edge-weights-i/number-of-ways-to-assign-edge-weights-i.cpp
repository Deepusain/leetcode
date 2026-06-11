class Solution {
private:
    // Badi power ko Modulo ke sath fast nikalne ke liye Binary Exponentiation
    long long power(long long base, long long exp, long long mod) {
        long long res = 1;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return res;
    }

public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1; // Tree me total nodes kitne hain
        long long MOD = 1e9 + 7;
        
        // 1. Adjacency List (Graph) ready karna
        vector<vector<int>> adj(n + 1);
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        // 2. BFS ka use karke Root 1 se maximum depth (L) nikalna
        queue<pair<int, int>> q; // {node, current_depth}
        vector<bool> visited(n + 1, false);
        
        q.push({1, 0}); // Root 1 ki depth 0 hai (edges ki count 0 hai)
        visited[1] = true;
        
        int max_depth = 0; // Yahi hamara L (maximum path length) hoga
        
        while (!q.empty()) {
            auto [curr_node, depth] = q.front();
            q.pop();
            
            max_depth = max(max_depth, depth); // Maximum depth ko update karein
            
            for (int neighbor : adj[curr_node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push({neighbor, depth + 1}); // Agle node ki depth +1 hogi
                }
            }
        }
        
        // 3. Agar maximum depth 0 hai, to 1 tarika hoga
        if (max_depth == 0) return 1;
        
        // Hamara final answer 2^(max_depth - 1) % MOD hoga
        return power(2, max_depth - 1, MOD);
    }
};
