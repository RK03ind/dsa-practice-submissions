class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        int prefixSum = 0;
        mp[0] = 1;

        int count = 0;

        for(const int &i: nums){
            prefixSum += i;
            if(mp.count(prefixSum - k)){
                count+=mp[prefixSum - k];
            }

            mp[prefixSum]++;
        }
        return count;
    }
};