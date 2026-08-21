class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        int n = heights.size();
        stack<int> st;
        int res = 0;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[i] < heights[st.top()]) {
                int idx = st.top();
                st.pop();
                int height = heights[idx];
                int width = 0;
                if (st.empty()) width = i;
                else width = i - st.top() - 1;
                int area = height * width;
                if (area > res) {
                    res = area;
                }
            }
            st.push(i);
        }
        
        return res;
    }
};
