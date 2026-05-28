class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();

        int left = 0, right = m - 1 , targetRow = -1;
        while(left <= right){
            int mid = (left + right) / 2;

            if(target < matrix[mid][0]){
                right = mid - 1;
            }else if(target > matrix[mid][n -1]){
                left = mid + 1;
            }else if (target >= matrix[mid][0] && target <= matrix[mid][n - 1]){
                targetRow = mid;
                break;
            }
        }
        if(targetRow == -1) return false;

        left = 0, right = n-1;
        while(left <= right){
            int mid = (left + right) / 2;

            if(target < matrix[targetRow][mid]){
                right = mid - 1;
            }else if(target > matrix[targetRow][mid]){
                left = mid + 1;
            }else{
                return true;
            }
        }

        return false;
    }
};
