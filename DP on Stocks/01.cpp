/*
    Leetcode Link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
*/


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        int profit=0;
        int buy=prices[0];
        for(int i=1;i<n;i++){
           int cost = prices[i]-buy;
           profit = max(profit,cost);
           buy = min(buy,prices[i]);
        }
        return profit;
    }
};



Time Complexity:   O(N)

Space Complexity:  O(1) 
