/*
    
You are given an array prices where prices[i] is the price of a given stock on the ith day.
Find the maximum profit you can achieve. You may complete at most two transactions.
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).


 Leetcode Link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/

*/

// Appoach-1 (Recursion)

class Solution {
public:
    int f(int ind,int Buy,int cap,vector<int>& prices){
        if(cap==0) return 0;
        if(ind==prices.size()) return 0;
        int profit=0;
        if(Buy){
            profit = max(-prices[ind]+f(ind+1,0,cap,prices), 0 + f(ind+1,1,cap,prices));
        }else{
            profit = max(prices[ind]+f(ind+1,1,cap-1,prices), 0 + f(ind+1,0,cap,prices));
        }
        return profit;
    }
    int maxProfit(vector<int>& prices) {
       return f(0,1,2,prices);
    }
};


Time complexity: O(2^n)
Space Complexity: O(n)


// Appoach-2 (Recursion + memorization)

class Solution {
public:
    int f(int ind,int Buy,int cap,vector<int>& prices,vector<vector<vector<int>>>&dp){
        if(cap==0) return 0;
        if(ind==prices.size()) return 0;
        if(dp[ind][Buy][cap] != -1) return dp[ind][Buy][cap];
        int profit=0;
        if(Buy){
            profit = max(-prices[ind]+f(ind+1,0,cap,prices,dp), 0 + f(ind+1,1,cap,prices,dp));
        }else{
            profit = max(prices[ind]+f(ind+1,1,cap-1,prices,dp), 0 + f(ind+1,0,cap,prices,dp));
        }
        return dp[ind][Buy][cap]= profit;
    }
    int maxProfit(vector<int>& prices){
        int n = prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(2,-1)));
       return f(0,1,2,prices,dp);
    }
};



Time complexity: O(N*2*3) 
Space Complexity:O(N*2*3) +O(N)


// Appoach-3 (tabulation)


class Solution {
public:
    int maxProfit(vector<int>& prices){
        int n = prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        dp[n][0][0]=dp[n][1][0]=0;
        for(int ind=n-1; ind>=0; ind--){
            for(int Buy=0; Buy<2; Buy++){
                for(int cap=1; cap<3; cap++){
                    int profit=0;
                    if(Buy){
                        profit = max(-prices[ind]+dp[ind+1][0][cap], 0 + dp[ind+1][1][cap]);
                    }else{
                        profit = max(prices[ind]+dp[ind+1][1][cap-1], 0 + dp[ind+1][0][cap]);
                    }
                   dp[ind][Buy][cap]= profit;
                 }               
            }
        }
        return dp[0][1][2];
    }
};




Time complexity: O(N*2*3) 
Space Complexity: O(N*2*3) 




// Appoach-4 (Space Optimization)


class Solution {
public:
    int maxProfit(vector<int>& prices){
        int n = prices.size();
        vector<vector<int>>ahead(2,vector<int>(3,0)),cur(2,vector<int>(3,0));
        //dp[n][0][0]=dp[n][1][0]=0;
        for(int ind=n-1; ind>=0; ind--){
            for(int Buy=0; Buy<2; Buy++){
                for(int cap=1; cap<3; cap++){
                    int profit=0;
                    if(Buy){
                        profit = max(-prices[ind]+ahead[0][cap], 0 + ahead[1][cap]);
                    }else{
                        profit = max(prices[ind]+ahead[1][cap-1], 0 + ahead[0][cap]);
                    }
                   cur[Buy][cap]= profit;
                 }               
            }
            ahead=cur;
        }
        return ahead[1][2];
    }
};



Time complexity: O(N*2*3) 
Space Complexity: O(2*2*3)



class Solution {
public:
    int maxProfit(vector<int>& prices){
        int n = prices.size();
        vector<vector<int>>ahead(2,vector<int>(3,0));
        //dp[n][0][0]=dp[n][1][0]=0;
        for(int ind=n-1; ind>=0; ind--){
            for(int Buy=0; Buy<2; Buy++){
                for(int cap=1; cap<3; cap++){
                    int profit=0;
                    if(Buy){
                        profit = max(-prices[ind]+ahead[0][cap], 0 + ahead[1][cap]);
                    }else{
                        profit = max(prices[ind]+ahead[1][cap-1], 0 + ahead[0][cap]);
                    }
                   ahead[Buy][cap]= profit;
                 }               
            }
        }
        return ahead[1][2];
    }
};



Time complexity: O(N*2*3) 
Space Complexity: O(2*3)



...................................................optimal.............................................................



// Appoach-1 (Recursion)
    

class Solution {
public: 
    int f(int ind,int transaction,vector<int> &prices){
        if(transaction==4)return 0;
        if(ind == prices.size())return 0;
        int profit = 0;
        if(transaction%2==0){
           profit = max(-prices[ind]+ f(ind+1,transaction+1,prices),f(ind+1,transaction,prices));
        }else{
            profit = max(prices[ind]+ f(ind+1,transaction+1,prices),f(ind+1,transaction,prices));
        }
      return profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        return f(0,0,prices);
    }
};






Time complexity: O(4^n)
Space Complexity: O(n)


// Appoach-2 (Recursion + memorization)




class Solution {
public: 
    int f(int ind,int transaction,vector<int> &prices,vector<vector<int>>&dp){
        if(transaction==4)return 0;
        if(ind == prices.size())return 0;
        if(dp[ind][transaction]!=-1)return dp[ind][transaction];
        int profit = 0;
        if(transaction%2==0){
           profit = max(-prices[ind]+ f(ind+1,transaction+1,prices,dp),0+f(ind+1,transaction,prices,dp));
        }else{
            profit = max(prices[ind]+ f(ind+1,transaction+1,prices,dp),0+f(ind+1,transaction,prices,dp));
        }
      return dp[ind][transaction]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int> (4,-1));
        return f(0,0,prices,dp);
    }
};



Time complexity: O(n*4)
Space Complexity: O(n*4)+O(n)


// Appoach-3 (tabulation)



class Solution {
public:
 int maxProfit(vector<int>& prices) {
    int n=prices.size();
    vector<vector<int>> dp(n+1,vector<int> (5,0));
    for(int ind=n-1;ind>=0;ind--){
        for(int transaction=0;transaction<4;transaction++){
            int profit=0;
            if(transaction%2==0){
                profit=max(-prices[ind]+dp[ind+1][transaction+1],dp[ind+1][transaction]);
            }else{
                profit=max(prices[ind]+dp[ind+1][transaction+1],dp[ind+1][transaction]);
            }
         dp[ind][transaction]=profit;
        }
    }
    return dp[0][0];
 }
};



Time complexity: O(n*5)
Space Complexity: O(n*5)




// Appoach-4 (Space Optimization)




class Solution {
public:
 int maxProfit(vector<int>& prices) {
    int n=prices.size();
    vector<int> ahead(5,0),curr(5,0);
    for(int ind=n-1;ind>=0;ind--){
        for(int transaction=0;transaction<4;transaction++){
            int profit=0;
            if(transaction%2==0){
                profit=max(-prices[ind]+ahead[transaction+1],ahead[transaction]);
            }else{
                profit=max(prices[ind]+ahead[transaction+1],ahead[transaction]);
            }
         curr[transaction]=profit;
        }
        ahead=curr;
    }
    return ahead[0];
 }
};



Time complexity: O(n*4)
Space Complexity: O(2*5)




1-d array optimization:




class Solution {
public:
 int maxProfit(vector<int>& prices) {
    int n=prices.size();
    vector<int> ahead(5,0);
    for(int ind=n-1;ind>=0;ind--){
        for(int transaction=0;transaction<4;transaction++){
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



Time complexity: O(n*4)
Space Complexity: O(5)
