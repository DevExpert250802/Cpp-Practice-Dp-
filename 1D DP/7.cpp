198. House Robber
You are a professional robber planning to rob houses along a street.
Each house has a certain amount of money stashed, 
the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

Example 1:
Input: nums = [1,2,3,1]
Output: 4
  
Example 2:
Input: nums = [2,7,9,3,1]
Output: 12

Constraints:   1 <= nums.length <= 100     ,     0 <= nums[i] <= 400

---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// Recursion

class Solution {
public:
int f(int n,vector<int>&arr){
    if(n<0) return 0;
    if(n==0) return arr[0];
    int take=arr[n]+f(n-2,arr);
    int notTake=0+f(n-1,arr);
    return max(take,notTake);
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        return f(n-1,nums);
    }
};

T.C.=O(2^N)
S.C.= O(N)




// Memorization
  
class Solution {
public:
int f(int n,vector<int>&arr,vector<int>&dp){
    if(n<0) return 0;
    if(n==0) return arr[0];
    if(dp[n]!=-1) return dp[n];
    int take=arr[n]+f(n-2,arr,dp);
    int notTake=0+f(n-1,arr,dp);
    return dp[n]=max(take,notTake);
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return f(n-1,nums,dp);
    }
};



T.C.=O(N)
S.C.= O(N) + O(N)


  // Tabulation

class Solution {
public:

    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,0);
        dp[0]=nums[0];
        for(int i=1;i<n;i++){
            int take=nums[i];
            if(i>1)take+=dp[i-2];
            int notTake=0+dp[i-1];
            dp[i]=max(take,notTake);
       }
       return dp[n-1];
    }
};



T.C.=O(N)
S.C.= O(N) 



// Space Optimization
  
class Solution {
public:

    int rob(vector<int>& nums) {
        int n=nums.size();
        int prev1=nums[0], prev2=0;
        for(int i=1;i<n;i++){
            int take=nums[i];
            if(i>1)take+=prev2;
            int notTake=0+prev1;
            int curr=max(take,notTake);
            prev2=prev1;
            prev1=curr;
       }
       return prev1;
    }
};


T.C.=O(N)
S.C.= O(1) 
