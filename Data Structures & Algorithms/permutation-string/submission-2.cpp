class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l = s1.length();
        int n = s2.length();
        if (l > n) return false;
        vector<int> freqS1(26, 0);
        vector<int> freqWindow(26, 0);
        for (int i = 0; i < l; i++) {
            freqS1[s1[i] - 'a']++;
            freqWindow[s2[i] - 'a']++;
        }
        for (int i = l; i < n; i++) {
            if (freqS1 == freqWindow) return true;
            freqWindow[s2[i - l] - 'a']--;
            freqWindow[s2[i] - 'a']++;
        }
        if (freqS1 == freqWindow) return true;
        return false;
    }
};
