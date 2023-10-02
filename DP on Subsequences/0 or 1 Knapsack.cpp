// 0/1 Knapsack


// A thief wants to rob a store. He is carrying a bag of capacity W. The store has ‘n’ items. 
// Its weight is given by the ‘wt’ array and its value by the ‘val’ array.
//  He can either include an item in its knapsack or exclude it but can’t partially have it as a fraction. 
// We need to find the maximum value of items that the thief can steal.





#include <bits/stdc++.h> 
int f(vector<int>&wt,vector<int>&val,int n,int W){
  if(n==0){
	  if(wt[0]<=W) return val[0];
	  else return 0;
  }
  int not_take = 0 + f(wt,val,n-1,W);
  int take = -1e9;
   if(wt[n]<=W)
  take = val[n]+f(wt,val,n-1,W-wt[n]);
  return max (not_take,take);

}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	return f(weight,value,n-1,maxWeight);
} 








#include <bits/stdc++.h> 
int f(vector<int>&wt,vector<int>&val,int ind,int W,vector<vector<int>>&dp){
  if(ind==0){
	  if(wt[0]<=W) return val[0];
	  else return 0;
  }
  if(dp[ind][W]!=-1) return dp[ind][W];

  int not_take = 0 + f(wt,val,ind-1,W,dp);
  int take = -1e9;
   if(wt[ind]<=W)
  take = val[ind]+f(wt,val,ind-1,W-wt[ind],dp);
  return dp[ind][W] = max(not_take,take);

}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
   vector<vector<int>> dp(n,vector<int>(maxWeight+1,-1));
	return f(weight,value,n-1,maxWeight,dp);
} 








#include <bits/stdc++.h> 

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
   vector<vector<int>> dp(n,vector<int>(maxWeight+1,0));
	
  for(int i=weight[0]; i<=maxWeight; i++){
        dp[0][i] = value[0];
    }
     for(int ind =1; ind<n; ind++){
        for (int cap = 0; cap <= maxWeight; cap++) {

          int notTaken = 0 + dp[ind - 1][cap];

          int taken = INT_MIN;
          if (weight[ind] <= cap)
            taken = value[ind] + dp[ind - 1][cap - weight[ind]];

          dp[ind][cap] = max(notTaken, taken);
        }
     }

     return dp[n - 1][maxWeight];
}









#include <bits/stdc++.h> 

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
  
   vector<int> prev(maxWeight+1,0),cur(maxWeight+1,0);
	
  for(int i=weight[0]; i<=maxWeight; i++){
        prev[i] = value[0];
    }
     for(int ind =1; ind<n; ind++){
        for (int cap = 0; cap <= maxWeight; cap++) {

          int notTaken = 0 + prev[cap];

          int taken = INT_MIN;
          if (weight[ind] <= cap)
            taken = value[ind] + prev[cap - weight[ind]];

          cur[cap] = max(notTaken, taken);
        }
        prev=cur;
     }

     return prev[maxWeight];
}














#include <bits/stdc++.h> 

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
  
   vector<int> prev(maxWeight+1,0);

   for (int i = weight[0]; i <= maxWeight; i++) {
     prev[i] = value[0];
   }
     for(int ind=1; ind<n; ind++){
       for (int cap = maxWeight; cap >= 0; cap--) {

         int notTaken = 0 + prev[cap];

         int taken = INT_MIN;
         if (weight[ind] <= cap)
           taken = value[ind] + prev[cap - weight[ind]];
           
          prev[cap] = max(notTaken, taken);
        }
     }

     return prev[maxWeight];
}


