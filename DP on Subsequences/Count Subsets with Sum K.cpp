
/* We are given an array ‘ARR’ with N positive integers and an integer K. 
  We need to find the number of subsets whose sum is equal to K. */





int f(int ind, int target, vector<int>&arr){
    if(target==0) return 1;
    if(ind == 0) return arr[0] == target;
    int notTaken = f(ind-1,target,arr);
    int taken = 0;
    if(arr[ind]<=target)
        taken = f(ind-1,target-arr[ind],arr);
    return  notTaken + taken;
}

int findWays(vector<int> &num, int k){
    int n = num.size();
    return f(n-1,k,num);
}




//   or




int f(int ind, int s , vector<int>& arr, int n, int sum) {
    // condition satisfied
    if (ind == n) {
        if (s== sum) {
            return 1;
        }
        // condition not satisfied
      else  return 0;
    }

    // take or pick the particular index into the subsequence
    s += arr[ind];
    
  int l =f(ind + 1, s, arr, n, sum);
   
     s-=arr[ind];
    // not take or not pick the particular index into the subsequence
    int r = f(ind + 1,s, arr, n, sum);
    return l+r;
}


int findWays(vector<int> &num, int k){
    int n = num.size();
    return f(0,0, num, n, k);
}











int mod =(int)(1e9+7);
int f(int ind, int target, vector<int>& arr, vector<vector<int>> &dp){
    if(target==0)
        return 1;
     

    if(ind == 0)
        return arr[0] == target;
    
    if(dp[ind][target]!=-1)
        return dp[ind][target];
        
    int notTaken = f(ind-1,target,arr,dp);
    
    int taken = 0;
    if(arr[ind]<=target)
        taken = f(ind-1,target-arr[ind],arr,dp);
        
    return dp[ind][target]= (notTaken + taken)%mod;
}

int findWays(vector<int> &num, int k) {
   int n = num.size();
   
    vector<vector<int>> dp(n,vector<int>(k+1,-1));
    return f(n-1,k,num,dp);
}







int mod = (int)(1e9 + 7);

int findWays(vector<int> &num, int k){
     int n = num.size();

    vector<vector<int>> dp(n,vector<int>(k+1,0));
    
    for(int i=0; i<n; i++){
        dp[i][0] = 1;
    }
    
    if(num[0]<=k) dp[0][num[0]] = 1;
    
    for(int ind = 1; ind<n; ind++){
        for(int target= 1; target<=k; target++){
            
            int notTaken = dp[ind-1][target];
    
            int taken = 0;
                if(num[ind]<=target)
                    taken = dp[ind-1][target-num[ind]];
        
            dp[ind][target]= (notTaken + taken)%mod;;
        }
    }
    
    return dp[n-1][k];








int mod =(int)(1e9+7);
int findWays(vector<int> &num, int k){
    int n = num.size();

    vector<int> prev(k+1,0);
    
    prev[0] =1;
    
    if(num[0]<=k)
        prev[num[0]] = 1;
    
    for(int ind = 1; ind<n; ind++){
        vector<int> cur(k+1,0);
        cur[0]=1;
        for(int target= 1; target<=k; target++){
            
            int notTaken = prev[target];
    
            int taken = 0;
                if(num[ind]<=target)
                    taken = prev[target-num[ind]];
        
            cur[target]= (notTaken + taken)%mod;
        }
        
        prev = cur;
    }
    
    return prev[k];
    
}

