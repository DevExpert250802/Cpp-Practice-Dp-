/* We are given an ARR array with N positive integers. We need to partition the array into two subsets such that the absolute difference of the sum of elements of the subsets is minimum.

We need to return only the minimum absolute difference of the sum of elements of the two partitions. */





bool f(int ind,int target,vector<int>&arr,vector<vector<int>>&dp) {
  if (target == 0)
    return dp[ind][target]=true;

  if (ind == 0)
    return dp[ind][target] = arr[0] == target;

  if (dp[ind][target] != -1)
    return dp[ind][target];
  bool notTaken = f(ind - 1, target, arr, dp);
  bool taken = false;
  if (arr[ind] <= target)
    taken = f(ind-1, target-arr[ind],arr,dp);
  return dp[ind][target] = notTaken||taken;
}

int minSubsetSumDifference(vector < int > & arr, int n) {
  int totSum = 0;
  for (int i = 0; i < n; i++) {
    totSum += arr[i];
  }
  vector<vector<int>>dp(n,vector<int>(totSum+1,-1));
  for (int i = 0; i <= totSum; i++) {
    bool dummy = f(n - 1, i, arr, dp);
  }
  int mini = 1e9;
  for (int i = 0; i <= totSum; i++) {
    if (dp[n - 1][i] == true) {
      int diff = abs(i - (totSum - i));
      mini = min(mini, diff);
    }
  }
  return mini;
}



Time Complexity: O(N*totSum) +O(N) +O(N)
Space Complexity: O(N*totSum) + O(N)





int minSubsetSumDifference(vector<int>& arr, int n)
{
	  int totsum=0;
      for(int i=0;i<n;i++) totsum+=arr[i];
          vector<vector<bool>> dp(n, vector<bool>(totsum + 1,false));
           for (int i = 0; i < n; i++) dp[i][0] = true;
           if(arr[0]<=totsum)
            dp[0][arr[0]] = true;

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= totsum; j++) {
            bool not_take = dp[i - 1][j];
            bool take = false; 
            if (j >= arr[i])
                take = dp[i - 1][j - arr[i]];

            dp[i][j] = take || not_take; 
        }
    }
         int mini=1e9;
         for(int i=0;i<=totsum/2;i++){
          if (dp[n - 1][i] == true) {
            mini = min(mini, abs((totsum -i)- i));
        }
     }
         return mini;
}




Time Complexity: O(N*totSum) +O(N) +O(N)
Space Complexity: O(totSum)




int minSubsetSumDifference(vector<int>& arr, int n)
{ 
        int totSum = 0;

  for (int i = 0; i < n; i++) {
    totSum += arr[i];
  }
        vector < bool > prev(totSum + 1, false),cur(totSum + 1, false);

  prev[0] = true;

  if (arr[0] <= totSum)
    prev[arr[0]] = true;

  for (int ind = 1; ind < n; ind++) {
    cur[0] = true;
    for (int target = 1; target <= totSum; target++) {
      bool notTaken = prev[target];

      bool taken = false;
      if (arr[ind] <= target)
        taken = prev[target - arr[ind]];

      cur[target] = notTaken || taken;
    }
    prev = cur;
  }

  int mini = 1e9;
  for (int i = 0; i <= totSum/2; i++) {
    if (prev[i] == true) {
      int diff = abs(i - (totSum - i));
      mini = min(mini, diff);
    }
  }
  return mini;
}





Time Complexity: O(N*totSum) +O(N) +O(N)
Space Complexity: O(N*totSum)







int minSubsetSumDifference(vector<int>& arr, int n){
    int totSum = accumulate(arr.begin(), arr.end(), 0);
    int target = totSum / 2;
        vector < bool > prev(totSum + 1, false),cur(totSum + 1, false);

  prev[0] = true;

  if (arr[0] <= totSum)
    prev[arr[0]] = true;

  for (int ind = 1; ind < n; ind++) {
    cur[0] = true;
    for (int target = 1; target <= totSum; target++) {
      bool notTaken = prev[target];

      bool taken = false;
      if (arr[ind] <= target)
        taken = prev[target - arr[ind]];

      cur[target] = notTaken || taken;
    }
    prev = cur;
  }

  int mini = 1e9;
  for (int i = 0; i <= totSum/2; i++) {
    if (prev[i] == true) {
      int diff = abs(i - (totSum - i));
      mini = min(mini, diff);
    }
  }
  return mini;
}



Time Complexity: O(n * total sum/2) +O(N) +O(N)
Space Complexity: O(total sum/2)
