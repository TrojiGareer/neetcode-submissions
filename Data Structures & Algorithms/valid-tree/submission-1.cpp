class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() > n - 1) return false;
        vector<vector<int>> adj(n);
        for (auto const& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        queue<int> q;
        vector<bool> visited(n, false);
        q.push(0);
        visited[0] = true;
        int vis = 0;
        while(!q.empty()) {
            int crt = q.front();
            q.pop();
            vis++;

            for (int neigh : adj[crt]) {
                if (!visited[neigh]) {
                    visited[neigh] = true;
                    q.push(neigh);
                    
                }
            }
        }
        return vis == n;
    }
};
