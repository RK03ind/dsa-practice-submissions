class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum = 0, maxSum = INT_MIN;
        // currSum = maxSum = ;

        for(const int &i: nums){
            currSum = max(i, (currSum + i));
            maxSum = max(currSum, maxSum);
        }

        return maxSum;
    }
};
