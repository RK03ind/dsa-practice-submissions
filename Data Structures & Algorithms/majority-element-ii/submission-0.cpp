class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
       unordered_set <int> res;
        for(const int &i:nums){
            mp[i]++;
            if(mp[i] > (nums.size()/3)){
                res.insert(i);
            }
        }

        return vector<int>(res.begin(), res.end());
    }
};