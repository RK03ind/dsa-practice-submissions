class Solution {
   public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars;
        vector<double> res;
        for (int i = 0; i < speed.size(); i++) {
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.begin(), cars.end(), greater<pair<int, int>>());

        for (auto car : cars) {
            double time = ((double)(target - car.first) / car.second);
            cout << "Time: " << target <<" - " << car.first <<" = " << (double)target - car.first <<endl;
            if (res.empty()) {
                res.push_back(time);
            } else if (res.back() >= time) {
                continue;
            } else{
                res.push_back(time);
            }
            cout << res.back() << endl;
        }

        return res.size();
    }
};
