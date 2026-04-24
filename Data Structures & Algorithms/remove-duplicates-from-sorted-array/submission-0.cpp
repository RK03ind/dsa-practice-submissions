class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int res = 1;
        if(nums.size() == 1) return 1;
        int i = 0, j= 1;

        while(i <= j && j < nums.size()){
            if(nums[i] == nums[j]){
                j++;
            }else{
                res++;
                nums[++i] = nums[j];
            }
        }

        return res;
    }
};