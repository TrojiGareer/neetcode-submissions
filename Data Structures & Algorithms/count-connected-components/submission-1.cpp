class Solution {
public:
    // returnam radacina componentei
    int find(int node, vector<int>& parent) {
        if (parent[node] == node) return node;

        return parent[node] = find(parent[node], parent);
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> parent(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        int comp = n;
        for (auto const& edge : edges) {
            int radacina0 = find(edge[0], parent);
            int radacina1 = find(edge[1], parent);
            // daca au radacina diferita, dar noi am plecat de la muchia initiala intre ele, ele formeaza de fapt o singura componenta
            if (radacina0 != radacina1) {
                comp--;
                parent[radacina0] = parent[radacina1];
            }
        }
        return comp;
    }
};
