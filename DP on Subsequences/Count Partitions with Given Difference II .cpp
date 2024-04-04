

Count Partitions with Given Difference



We are given an array ‘ARR’ with N positive integers and an integer D.
 We need to count the number of ways we can partition the given array into two subsets,
 S1 and S2 such that S1 – S2 = D and S1 is always greater than or equal to S2.





/*  We have the following two conditions given to us.
    S1 - S2 = D   – (i)
    S1 >= S2     – (ii)
    S1 = totSum – S2      – (iii)

    Now solving for equations (i) and (iii), we can say that 

    totSum – S2-S2=D

    S2 = (totSum – D)/2    – (iv)

     Edge Cases:

  The following edge cases need to be handled:

  As the array elements are positive integers including zero, we don’t want to find the case when S2 is negative or we can say that totSumis lesser than D, therefore if totSum<D, we simply return 0.

 S2 can’t be a fraction, as all elements are integers, therefore if totSum – D is odd, we can return 0. */







#include <bits/stdc++.h> 
int mod =(int)1e9+7;
int f(int ind, int sum, vector<int>& arr){

    if(ind == 0){
            if(sum==0 && arr[0]==0)return 2;
            if(sum==0 || sum == arr[0])return 1;
            return 0;
    }      
    int notTaken = f(ind-1,sum,arr);
    
    int taken = 0;
    if(arr[ind]<=sum)
        taken = f(ind-1,sum-arr[ind],arr);
        
    return (notTaken + taken)%mod;
}
int countPartitions(int n, int d, vector<int> &arr) {
    
  int totsum=0;
 /* for(int i=0; i<arr.size();i++){
        totSum += arr[i];
    }*/
  for(auto&it:arr) totsum+=it;
     //Checking for edge cases
    if(totsum-d<0) return 0;
    if((totsum-d)%2==1) return 0;
    
    int s2 = (totsum-d)/2;
     return f(n-1,s2,arr);
}









#include <bits/stdc++.h> 
int mod =(int)1e9+7;
int f(int ind, int sum, vector<int>& arr,vector<vector<int>>&dp){

    if(ind == 0){
            if(sum==0 && arr[0]==0)return 2;
            if(sum==0 || sum == arr[0])return 1;
            return 0;
    }    

    if(dp[ind][sum]!=-1) return dp[ind][sum];
  
    int notTaken = f(ind-1,sum,arr,dp);
  
    int taken = 0;
    if(arr[ind]<=sum)
        taken = f(ind-1,sum-arr[ind],arr,dp);
        
    return dp[ind][sum]= (notTaken + taken)%mod;
}
int countPartitions(int n, int d, vector<int> &arr) {
    
  int totsum=0;
 /* for(int i=0; i<arr.size();i++){
        totSum += arr[i];
    }*/
  for(auto&it:arr) totsum+=it;
     //Checking for edge cases
    if(totsum-d<0) return 0;
    if((totsum-d)%2==1) return 0;
    
    int s2 = (totsum-d)/2;
    vector<vector<int>> dp(n,vector<int>(s2+1,-1));
  
     return f(n-1,s2,arr,dp);
  
}








#include <bits/stdc++.h> 
using namespace std;

const int mod = 1e9 + 7;

int countPartitions(int n, int d, vector<int> &arr) {
    int totSum = accumulate(arr.begin(), arr.end(), 0);

    if (totSum < d || (totSum - d) % 2 != 0)
        return 0;

    int s2 = (totSum - d) / 2;
    vector<vector<int>> dp(n, vector<int>(s2 + 1, 0));

    if (arr[0] == 0) dp[0][0] = 2; // 2 cases - pick and not pick
    else dp[0][0] = 1; // 1 case - not pick

    if (arr[0] != 0 && arr[0] <= s2)
        dp[0][arr[0]] = 1; // 1 case - pick

    for (int ind = 1; ind < n; ind++) {
        for (int target = 0; target <= s2; target++) {
            int notTaken = dp[ind - 1][target];
            int taken = 0;
            if (arr[ind] <= target)
                taken = dp[ind - 1][target - arr[ind]];

            dp[ind][target] = (notTaken + taken) % mod;
        }
    }

    return dp[n - 1][s2];
}



    

#include <bits/stdc++.h> 
const int mod = 1e9 + 7;

int countPartitions(int n, int d, vector<int> &arr){
 int totSum = accumulate(arr.begin(), arr.end(), 0);

    if (totSum < d || (totSum - d) % 2 != 0) return 0;

    int s2 = (totSum - d) / 2;
     vector<int> prev(s2+1,0),cur(s2+1,0);

    if (arr[0] == 0)
        prev[0] = 2; // 2 cases - pick and not pick
    else
        prev[0] = 1; // 1 case - not pick

    if (arr[0] != 0 && arr[0] <= s2)
        prev[arr[0]] = 1; // 1 case - pick

    for (int ind = 1; ind < n; ind++) {
        for (int target = 0; target <= s2; target++) {
            int notTaken = prev[target];
            int taken = 0;
            if (arr[ind] <= target)
                taken = prev[target - arr[ind]];

            cur[target] = (notTaken + taken) % mod;
        }
        prev=cur;
    }

    return prev[s2];
}
