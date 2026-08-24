#include <cstring>
class Solution {
public:
    string minWindow(string s, string t) {
        if (s.length() < t.length()) return "";
        vector<int> freqT(128, 0);
        vector<int> freqWindow(128, 0);
        int required = 0; 
        for (char c : t) {
            if (freqT[c] == 0) required++;
            freqT[c]++;
        }
        int st = 0, matched = 0;
        int res = INT_MAX;
        int startIdx = 0;
        for (int dr = 0; dr < s.length(); dr++) {
            freqWindow[s[dr]]++;
            if (freqT[s[dr]] > 0 && freqWindow[s[dr]] == freqT[s[dr]]) matched++;

            while (matched == required) {
                int len = dr - st + 1;
                if (len < res) {
                    res = len;
                    startIdx = st;
                }
                freqWindow[s[st]]--;
                if (freqT[s[st]] > 0 && freqWindow[s[st]] < freqT[s[st]]) matched--;
                st++;
            }
        }
        if (res == INT_MAX) {
            return "";
        }
        return s.substr(startIdx, res);
    }
};
