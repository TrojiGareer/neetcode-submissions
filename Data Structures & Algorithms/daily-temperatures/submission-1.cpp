class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);
        for (int i = n - 2; i >= 0; i--) {
            int j = i + 1;
            while (temperatures[i] >= temperatures[j]) {
                if (res[j] == 0) break;
                j = j + res[j];
            }
            if (temperatures[i] < temperatures[j])
                res[i] = j - i;
        }
        
        return res;
    }
};
