/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.
Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:
After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

leetcode link :  https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
*/

// Appoach-1 (Recursion)

class Solution {
public:
int f(int ind,int Buy,vector<int>& prices){
    if(ind >= prices.size()) return 0;
    int profit = 0;
    if(Buy){
        profit = max(-prices[ind]+f(ind+1,0,prices), 0+ f(ind+1,1,prices));
    }
    else{
        profit = max(prices[ind]+f(ind+2,1,prices), 0+ f(ind+1,0,prices));
    }
    return profit;
}

    int maxProfit(vector<int>& prices) {
        return f(0,1,prices);
    }
};

Time complexity: O(2^n)
Space Complexity: O(n)


  // Appoach-2 (Recursion + memorization)


class Solution {
public:
int f(int ind,int Buy,vector<int>& prices,vector<vector<int>>&dp){
    if(ind >= prices.size()) return 0;
    if(dp[ind][Buy] != -1) return dp[ind][Buy];

    int profit = 0;
    if(Buy){
        profit = max(-prices[ind]+f(ind+1,0,prices,dp), 0+ f(ind+1,1,prices,dp));
    }
    else{
        profit = max(prices[ind]+f(ind+2,1,prices,dp), 0+ f(ind+1,0,prices,dp));
    }
    return dp[ind][Buy] = profit;
}

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return f(0,1,prices,dp);
    }
};

Time complexity: O(n*2)
Space Complexity: O(n*2)+O(n)


// Appoach-3 (tabulation)



class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+2,vector<int>(2,0));
        // dp[n][0]=dp[n][1]=0;
        for(int ind=n-1;ind>=0;ind--){
            for(int Buy = 0;Buy<2;Buy++){
                int profit = 0;
                if(Buy){
                  profit = max(-prices[ind]+dp[ind+1][0], 0+  dp[ind+1][1]);
                }else{
                 profit = max(prices[ind]+dp[ind+2][1], 0+ dp[ind+1][0]);
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
    int maxProfit(vector<int>& prices) {
         int n = prices.size();
         vector<vector<int>>dp(n+2,vector<int>(2,0));
         for(int ind=n-1;ind>=0;ind--){
              dp[ind][1] = max(-prices[ind]+dp[ind+1][0], 0+  dp[ind+1][1]);
              dp[ind][0] = max(prices[ind] + dp[ind+2][1], 0+ dp[ind+1][0]);
             } 
      return dp[0][1];
    }
};



Time complexity: O(n)
Space Complexity: O(n*2)





class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;

        vector<int> ahead2(2, 0), ahead1(2, 0), cur(2, 0);

        for (int ind = n - 1; ind >= 0; ind--) {
            // When the state is to buy
            cur[1] = max(-prices[ind] + ahead1[0], ahead1[1]);
            // When the state is to sell
            cur[0] = max(prices[ind] + ahead2[1], ahead1[0]);

            ahead2 = ahead1;
            ahead1 = cur;
        }

        return cur[1];
    }
};





Time complexity: O(n)
Space Complexity: O(6)
