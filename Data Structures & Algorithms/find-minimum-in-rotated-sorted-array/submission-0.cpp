class Solution {
public:
    int findMin(vector<int> &nums) {
        int prev = nums[0], r = nums.size(), res;
        bool noDeflection = true;
        for(int i = 1; i <r; i++){
            if(nums[i] < prev){
                noDeflection = false;
                res = nums[i];
                break;
            }
            prev = nums[i];

        }

        if(noDeflection) return nums[0];

        return res;
    }
};
