class Solution {
   public:
    vector<int> twoSum(vector<int>& arr, int sum) {
        unordered_map<int, int> map;
        for (size_t i = 0; i < arr.size(); i++)
        {
            auto it = map.find(sum - arr[i]);
            if (it != map.end())
            {
                return {it->second, (int)i};
            }
            map.insert({arr[i], i});
        }
        return {};
    }
};
