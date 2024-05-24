/*
leetcode : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/

You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.
Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
*/



class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
    int n=prices.size();
    vector<int> ahead(2*k+1,0);
    for(int ind=n-1;ind>=0;ind--){
        for(int transaction=0;transaction<2*k;transaction++){
            int profit=0;
            if(transaction%2==0){
                profit=max(-prices[ind]+ahead[transaction+1],ahead[transaction]);
            }else{
                profit=max(prices[ind]+ahead[transaction+1],ahead[transaction]);
            }
         ahead[transaction]=profit;
        }
    }
    return ahead[0];
    }
};

Time complexity: O(n*2k)
Space Complexity: O(2k)
