class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        if (r == 0) return nums[0] == target ? 0 : -1;

        if (nums[l] <= nums[r]) {
            while (l <= r) {
                int mid = (l + r) / 2;

                if (nums[mid] == target) {
                    return mid;
                } else if (target > nums[mid]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }

        while (l <= r) {
            if (nums[l] == target) return l;
            if (nums[r] == target) return r;

            int mid = (l + r) / 2;
            cout << mid << endl;
            if (nums[mid] == target) return mid;

            if (nums[l] <= nums[mid]) {
                // l SORTED SECTION

                if (target > nums[l]) {
                    if (target < nums[mid]) {
                        r = mid - 1;
                    } else if (target > nums[mid]) {
                        l = mid + 1;
                    }
                } else if (target < nums[l]) {
                    l = mid + 1;
                }
            } else if (nums[mid] <= nums[l]) {
                // r SORTED SECTION
                if (target > nums[l]) {
                    r = mid - 1;
                } else if (target < nums[l]) {
                    if (target < nums[mid]) {
                        r = mid - 1;
                    } else if (target > nums[mid]) {
                        l = mid + 1;
                    }
                }
            }
        }
        return -1;
    }
};
