class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);

        for(auto const& pre : prerequisites) {
            adj[pre[0]].push_back(pre[1]);
            inDegree[pre[1]]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        int courses = 0;
        while (!q.empty()) {
            int crt = q.front();
            q.pop();
            courses++;
            for (int neigh : adj[crt]) {
                inDegree[neigh]--;
                if (inDegree[neigh] == 0) {
                    q.push(neigh);
                }
            }
        }
        return courses == numCourses;
    }
};
