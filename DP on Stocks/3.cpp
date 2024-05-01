int maxProfit(vector<int>& Arr)
{  int n = Arr.size();
    // Create two 2D arrays to store the profit information, one for the current state and one for the ahead state.
    vector<vector<int>> ahead(2, vector<int>(3, 0));

    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy <= 1; buy++) {
            for (int cap = 1; cap <= 2; cap++) {
                if (buy == 0) { // We can buy the stock
                    ahead[buy][cap] = max(0 + ahead[0][cap], 
                                        -Arr[ind] + ahead[1][cap]);
                }

                if (buy == 1) { // We can sell the stock
                    ahead[buy][cap] = max(0 + ahead[1][cap],
                                        Arr[ind] + ahead[0][cap - 1]);
                }
            }
        }
    }

    return ahead[0][2];
}




optimal






int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> prev(5,0);
        for(int i=n-1;i>=0;i--)
        {
            for(int t=0;t<4;t++)
            {
                 if(t%2==0)
                    prev[t]=max(-prices[i]+prev[t+1],prev[t]);
                else 
                    prev[t]=max(prices[i]+prev[t+1],prev[t]);
            }
        }
        return prev[0];
    }





Memoization:




 int help(int i,int t,vector<int> &prices,vector<vector<int>> &dp)
    {
        if(t==4)return 0;
        if(i==prices.size())return 0;
        if(dp[i][t]!=-1)return dp[i][t];
        if(t%2==0)
        return dp[i][t]=max(-prices[i]+help(i+1,t+1,prices,dp),help(i+1,t,prices,dp));
        else 
        return dp[i][t]=max(prices[i]+help(i+1,t+1,prices,dp),help(i+1,t,prices,dp));
    }

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int> (4,-1));
        return help(0,0,prices,dp);
    }



Tabulation



 int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int> (5,0));
        for(int i=n-1;i>=0;i--)
        {
            for(int t=0;t<4;t++)
            {
                 if(t%2==0)
                    dp[i][t]=max(-prices[i]+dp[i+1][t+1],dp[i+1][t]);
                else 
                    dp[i][t]=max(prices[i]+dp[i+1][t+1],dp[i+1][t]);
            }
        }
        return dp[0][0];
    }



Space optimized:




int maxProfit(vector<int>& prices) { 
        int n=prices.size();
        vector<int> ahead(5,0),curr(5,0);
        for(int i=n-1;i>=0;i--)
        {
            for(int t=0;t<4;t++)
            {
                 if(t%2==0)
                    curr[t]=max(-prices[i]+ahead[t+1],ahead[t]);
                else 
                    curr[t]=max(prices[i]+ahead[t+1],ahead[t]);
            }
            ahead=curr;
        }
        return ahead[0];
    }




1-d array optimization:



int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> ahead(5,0);
        for(int i=n-1;i>=0;i--)
        {
            for(int t=0;t<4;t++)
            {
                 if(t%2==0)
                    ahead[t]=max(-prices[i]+ahead[t+1],ahead[t]);
                else 
                    ahead[t]=max(prices[i]+ahead[t+1],ahead[t]);
            }
        }
        return ahead[0];
    }
