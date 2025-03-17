// Recursion (Exponential Time Complexity)
class Solution {
public:
    int f(int n){
        if (n<=1) return n;
        if (n==2) return 1;
        return f(n-1) + f(n-2) + f(n-3);
    }
    int tribonacci(int n) {
        return f(n);    
    }
};
// Time Complexity: O(3^N)  
// Space Complexity: O(N)  





// Memoization (Top-Down DP)
class Solution {
public:
    int f(int n, vector<int>& dp) {
        if (n<=1) return n;
        if (n==2) return 1;
        if (dp[n] != -1) return dp[n];
        return dp[n] = f(n-1, dp) + f(n-2, dp) + f(n-3, dp);
    }
    int tribonacci(int n) {
        vector<int> dp(n+1, -1);  
        return f(n, dp);  
    }
};
// Time Complexity: O(N)  
// Space Complexity: O(N)  





// Tabulation with Edge Case Handling (Bottom-Up DP)
class Solution {
public:
    int tribonacci(int n) {
        if (n <= 1) return n;
        if (n == 2) return 1;
        vector<int> dp(n+1);  
        dp[0] = 0, dp[1] = 1, dp[2] = 1;
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }
        return dp[n];
    }
};
// Time Complexity: O(N)  
// Space Complexity: O(N)  





// Space Optimized Approach (O(1) Space Complexity)
class Solution {
public:
    int tribonacci(int n) {
        if (n == 0) return 0;
        int prev3 = 0, prev2 = 1, prev1 = 1;
        for (int i = 3; i <= n; i++) {
            int curr = prev3 + prev2 + prev1;
            prev3 = prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};
// Time Complexity: O(N)  
// Space Complexity: O(1)  
