// LeetCode(509)


class Solution {
public:
   int fib(int n) {
         if(n<=1) return n;
           return fib(n-1)+fib(n-2);
        }

  }; 

// T.C. = O(2^N) S.C.= O(N)   overlapping subproblems -> solution : memorization 

class Solution {
public:
    int f(int n, vector<int>&dp)
    {
        if(n<=1) return n;
        if(dp[n]!=-1) return dp[n];
         return dp[n]=f(n-1,dp)+f(n-2,dp);
    }
    int fib(int n){
         vector<int>dp(n+1,-1);
         return f(n,dp);
    }
};
//T.C. = O(N) S.C.= O(N)+ O(N)  recursive stack space + dp space  -> solution : tabulation

class Solution {
public:
  int f(int n, vector<int>&dp) 
    {
      dp[0]=0 ; dp[1]=1;
      for(int i=2; i<=n; i++){
          dp[i]=f(i-1,dp)+f(i-2,dp);
          }
          return dp[n];
    }
    int fib(int n){
         vector<int>dp(n+1,-1);
         return f(n,dp);
    }
}; 
// T.C. = O(N) S.C. = O(N)   dp space -> solution : space optimize 

class Solution {
public:
    int fib(int n){
       int  prev2=0 , prev1=1;
       if(n==0) return 0;
       else{
        for(int i=2; i<=n; i++){
         int curr_i = prev2 + prev1;
         prev2=prev1;
          prev1=curr_i;
          }
       }
         return prev1;
    }
};     
// T.C. = O(N) S.C. = O(1)  





class Solution {
public:
    const int mod = 1e9 + 7;
    vector<vector<int>> multiply(vector<vector<int>> a, vector<vector<int>> b) {

        vector<vector<int>> c(2, vector<int>(2, 0));

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    // c[i][j] = (c[i][j] + (long long)((long long)a[i][k] *
                    // (long long)b[k][j])) % mod;
                    c[i][j] = (c[i][j] + (long long)(a[i][k]) * b[k][j]) % mod;
                }
            }
        }

        return c;
    }

    vector<vector<int>> f(vector<vector<int>>& a, int n) {

        if (n == 1)
            return a;

        vector<vector<int>> temp = f(a, n / 2);

        if (n % 2 == 0)
            return multiply(temp, temp);
        return multiply(temp, multiply(temp, a));
    }

    int fib(int n) {
        if (n == 0)
            return 0;
        vector<vector<int>> a = {{1, 1}, {1, 0}};
        vector<vector<int>> ans = f(a, n);

        return ans[1][0] % mod;
    }
};
// T.C. = O(log n) S.C. = O(log n) 
