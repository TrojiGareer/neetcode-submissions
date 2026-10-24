class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        vector<vector<int>> adj(26);
        vector<int> inDegree(26, 0);
        vector<bool> exists(26, false);
        vector<vector<bool>> edgeExists(26, vector<bool>(26, false));

        int letters = 0;
        for (const string& word : words) {
            for (char c : word) {
                if (!exists[c - 'a']) {
                    exists[c - 'a'] = true;
                    letters++;
                }
            }
        }

        for (int i = 0; i < words.size() - 1; i++) {
            string w1 = words[i];
            string w2 = words[i + 1];

            if (w1.length() > w2.length() && w1.substr(0, w2.length()) == w2) {
                return "";
            }

            int minLength = min(w1.length(), w2.length());
            for (int j = 0; j < minLength; j++) {
                if (w1[j] != w2[j]) {
                    int out = w1[j] - 'a';
                    int in = w2[j] - 'a';
                    if (!edgeExists[out][in]) {
                        edgeExists[out][in] = true;
                        adj[out].push_back(in);
                        inDegree[in]++;
                    }
                    break;
                }
            }
        }

        queue<int> q;
        for (int i = 0; i < 26; i++) {
            if (exists[i]) {
                if (inDegree[i] == 0) {
                    q.push(i);
                }
            }
        }

        string res = "";
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            res += (node + 'a');

            for (int neigh : adj[node]) {
                inDegree[neigh]--;
                if (inDegree[neigh] == 0) {
                    q.push(neigh);
                }
            }
        }
        if (res.length() == letters) return res;
        return "";
    }
};
