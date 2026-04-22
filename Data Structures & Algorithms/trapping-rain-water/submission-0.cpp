class Solution {
   public:
    int trap(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int leftMax = height[0], rightMax = height[j];
        int totalWater = 0;
        while (i < j) {
            if (leftMax < rightMax) {
                totalWater = totalWater + (leftMax - height[i]);
                i++;
                leftMax = max(leftMax, height[i]);

            } else {
                totalWater = totalWater + (rightMax - height[j]);
                j--;
                rightMax = max(rightMax, height[j]);
            }
        }

        return totalWater;
    }
};
