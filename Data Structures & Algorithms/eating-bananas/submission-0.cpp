class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxPile = -1;

        for (const int& i : piles) {
            maxPile = max(maxPile, i);
        }

        int l = 1, r = maxPile, k = maxPile;

        while (l <= r) {
             int mid = l + (r - l) / 2;

            long long  totalHours = 0;

            for (const int& i : piles) {
                int hours = (i + mid - 1) / mid;
                totalHours += hours;
            }

            if (totalHours <= h) {
                r = mid - 1;
                k = min(k, mid);
            } else if (totalHours > h) {
                l = mid + 1;
            }
        }

        return k;
    }
};