/*  There are N stones, numbered 1,2,…, N. For each i (1≤i≤N), the height of Stone i is h i.
There is a frog who is initially on Stone 1. He will repeat the following action some number of times to reach Stone N:
If the frog is currently on Stone I, jump to one of the following: Stone  i+1,i+2,…,i+K. Here, a cost of ∣h i−h j∣ is incurred, where j is the stone to land on.
Find the minimum possible total cost incurred before the frog reaches Stone N. */


#include <bits/stdc++.h>
int f(int ind, vector<int> &heights, int k) {
  if (ind == 0)return 0;
  int minsteps = INT_MAX;
  for (int j = 1; j <= k; j++) {
    if (ind - j >= 0) {
      int jump = f(ind - j, heights, k) + abs(heights[ind] - heights[ind - j]);
      minsteps = min(minsteps, jump);
    }
  }
  return minsteps;
}
int frogJump(int n, vector<int> &heights, int k) {
  return f(n - 1, heights, k);
}



// T.C. = O(2^N x k) S.C.= O(N)   overlapping subproblems -> solution : memorization 



int f(int ind, vector<int> &heights, int k,vector<int>& dp) {
  if (ind == 0)return 0;
  if(dp[ind]!=-1) return dp[ind];
  int minsteps = INT_MAX;
  for (int j = 1; j <= k; j++) {
    if (ind - j >= 0) {
      int jump = f(ind - j, heights, k,dp) + abs(heights[ind] - heights[ind - j]);
     minsteps = min(minsteps, jump);
    }
  }
  return dp[ind]= minsteps;
}

int minimizeCost(int n, int k, vector<int> &height){
  vector<int>dp(n,-1);
  return f(n-1,height,k,dp);
}



//T.C. = O(N*k) S.C.= O(N)+ O(N)  recursive stack space + dp space  -> solution : tabulation





int f(int n, vector<int>& height, vector<int>& dp, int k){
    dp[0]=0;
    for(int i=1;i<n;i++){
        int minsteps = INT_MAX;
        for(int j=1;j<=k;j++){
            if(i-j>=0){
                int jump = dp[i-j]+ abs(height[i]- height[i-j]);
                minsteps= min(jump, minsteps);
            }
        }
        dp[i]= minsteps;
    }
    return dp[n-1];
}

int minimizeCost(int n, int k, vector<int> &height){
     vector<int> dp(n,-1);
    return f(n, height, dp, k);
}






int minimizeCost(int n, int k, vector<int> &height) {
    vector<int> dp(n, 0);
    dp[0] = 0;
    //  index from 1
    for(int i = 1; i < n; i++) {
        int minsteps = INT_MAX;
        // Iterate through possible jumps up to k steps
        for (int j = 1; j <= k; j++) {
            if (i - j >= 0) {
                // Calculate cost of jumping from i-j to i
                int jump = dp[i - j] + abs(height[i] - height[i - j]);
                minsteps = min(minsteps, jump);
            }
        }
        dp[i] = minsteps;
    }
    return dp[n - 1];
}


// T.C. = O(N) S.C. = O(N)   dp space -> solution : space optimize 


// T.C. = O(N) S.C. = O(k)  in worst case O(N) so not necessary
