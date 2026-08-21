class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<double> res;
        vector<pair<int, int>> cars(position.size());
        for (int i = 0; i < position.size(); i++) {
            cars[i].first = (target - position[i]);
            cars[i].second = speed[i];
        }
        sort(cars.begin(), cars.end());
        for (int i = 0; i < cars.size(); i++) {
            double time = cars[i].first / double(cars[i].second);
            if (res.empty()) {
                res.push(time);
            }
            else {
                if (time > res.top()) {
                    res.push(time);
                }
            }
        }
        return res.size();
    }
};
