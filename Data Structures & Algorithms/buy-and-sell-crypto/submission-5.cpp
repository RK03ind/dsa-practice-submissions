class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = 101 , maxProfit=0; //since 100 is the maximum price mentioned in constraints
        for(int i = 1; i < prices.size(); i++){
            minPrice = min(minPrice, prices[i-1]);
            maxProfit = max(maxProfit, prices[i] - minPrice);
        }
        return maxProfit;
    }
};
