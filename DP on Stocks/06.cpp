/*
You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.
Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

Note:You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
The transaction fee is only charged once for each stock purchase and sale.

 Leetcode Link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/
*/

// Appoach-1 (Recursion)

class Solution {
public:
    int f(int ind, int Buy, vector<int>& prices,int fee){
        if(ind == prices.size())return 0;
        int profit = 0;
        if(Buy){
            profit = max(-prices[ind]+f(ind+1,0,prices,fee),0 + f(ind+1,1,prices,fee)); 
        }else{
           profit = max(prices[ind]-fee+f(ind+1,1,prices,fee), 0 + f(ind+1,0,prices,fee));
        }
        return profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        return f(0,1,prices,fee);
    }
};



Time complexity: O(2^n)
Space Complexity: O(n)


  // Appoach-2 (Recursion + memorization)




class Solution {
public:
    int f(int ind, int Buy, vector<int>& prices, int fee, vector<vector<int>>& dp) {
        if (ind == prices.size()) return 0;
        if (dp[ind][Buy] != -1) return dp[ind][Buy];

        int profit = 0;
        if (Buy) {
            profit = max(-prices[ind] + f(ind + 1, 0, prices, fee, dp), f(ind + 1, 1, prices, fee, dp));
        } else {
            profit = max(prices[ind] - fee + f(ind + 1, 1, prices, fee, dp), f(ind + 1, 0, prices, fee, dp));
        }

        return dp[ind][Buy] = profit;
    }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return f(0, 1, prices, fee, dp);
    }
};




Time complexity: O(n*2)
Space Complexity: O(n*2)+O(n)


// Appoach-3 (tabulation)


class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        // dp[n][0]=dp[n][1]=0;
        for(int ind=n-1;ind>=0;ind--){
            for(int Buy = 0;Buy<2;Buy++){
                int profit = 0;
                if(Buy){
                  profit = max(-prices[ind]+dp[ind+1][0], 0+  dp[ind+1][1]);
                }else{
                 profit = max(prices[ind]-fee+dp[ind+1][1], 0+ dp[ind+1][0]);
                }
               dp[ind][Buy] = profit;
            }
        } 
       return dp[0][1];
        
    }
};




Time complexity: O(n*2)
Space Complexity: O(n*2)




// Appoach-4 (Space Optimization)



class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int>ahead(2,0),cur(2,0);
        // dp[n][0]=dp[n][1]=0;
        for(int ind=n-1;ind>=0;ind--){
            for(int Buy = 0;Buy<2;Buy++){
                int profit = 0;
                if(Buy){
                  profit = max(-prices[ind]+ahead[0], 0 + ahead[1]);
                }else{
                 profit = max(prices[ind]-fee+ahead[1], 0 + ahead[0]);
                }
               cur[Buy] = profit;
            }
            ahead=cur;
        } 
       return ahead[1];
    }
};




Time complexity: O(n*2)
Space Complexity: O(2)




// Appoach-5 (Variables)



class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int ahead_notBuy, ahead_Buy,cur_notBuy,cur_Buy;
        ahead_notBuy = ahead_Buy=0;
        for(int ind=n-1;ind>=0;ind--){
            cur_Buy    = max(-prices[ind]+ahead_notBuy, 0 + ahead_Buy);
            cur_notBuy = max(prices[ind]-fee+ahead_Buy, 0 + ahead_notBuy);
            ahead_Buy  = cur_Buy;
            ahead_notBuy = cur_notBuy;
        }
       return ahead_Buy;
    }
};


Time complexity: O(n)
Space Complexity: O(1)
