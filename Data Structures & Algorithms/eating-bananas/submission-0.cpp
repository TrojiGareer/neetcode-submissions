class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int st = 1;
        int dr = 0;
        int n = piles.size();
        for (int i = 0; i < n; i++) {
            if (piles[i] > dr) dr = piles[i];
        }
        int res = dr;
        while (st <= dr) {
            int mid = st + (dr - st) / 2;
            long long hours = 0;
            for (int i = 0; i < n; i++) {
                hours += (piles[i] + mid - 1) / mid;
            }
            if (hours <= h) res = mid, dr = mid - 1;
            else st = mid + 1;
        }
        return res;
    }
};
