class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        int mid = (left + right) / 2; 
        while (left <= right){
            mid = (left + right) / 2; 
            if(nums[mid] == target){
                return mid;
            }else if(nums[right] > target){
                right--;
            }else if(nums[left] < target){
                left++;
            }
        }

        return left;
    }
};