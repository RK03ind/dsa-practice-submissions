class Solution {
    bool canSplit(vector<int>& nums, int k, int limit) {
        int subArrayCount = 1;
        int curr = 0;
        for (const int& i : nums) {
            if (curr + i > limit) {
                subArrayCount++;
                if(subArrayCount > k) return false;
                curr = i;
            } else {
                curr += i;
            }
        }
        return true;
    }

   public:
    int splitArray(vector<int>& nums, int k) {
        int max = *max_element(nums.begin(), nums.end());
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        int l = max, r = totalSum, res = r;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if(canSplit(nums, k, mid)){
                r = mid - 1;
                res = mid;    
            }else{
                l = mid + 1;
            }
        }
        return res;
    }
};