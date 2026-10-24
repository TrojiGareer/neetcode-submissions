class Solution {
public:
    void dfs(vector<bool>& visited, vector<vector<int>>& adj, int curr) {
        visited[curr] = true;

        for (int neigh : adj[curr]) {
            if (!visited[neigh]) 
                dfs(visited, adj, neigh);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);
        int conex = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                conex++;
                dfs(visited, adj, i);
            }
        }
        return conex;
    }
};
