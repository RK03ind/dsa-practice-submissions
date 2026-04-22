class Solution {
   public:
    vector<int> twoSum(vector<int>& arr, int sum) {
        unordered_map<int, int> mp;
        for (int i = 0; i < arr.size(); i++)
        {
            int diff = sum - arr[i];
            if (mp.find(diff) != mp.end())
            {
                return {mp[diff], i};
            }
            mp[arr[i]] = i;
        }
        return {};
    }
};
