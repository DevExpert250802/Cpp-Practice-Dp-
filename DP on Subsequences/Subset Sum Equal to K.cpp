/*Subset Sum Equal to K


We are given an array ‘ARR’ with N positive integers. We need to find if there is a subset in “ARR” with a sum equal to K. 
  If there is, return true else return false.*/




#include <bits/stdc++.h>

bool f(int ind, int k, vector<int> &arr) {
    if (k == 0) return true;
    if (ind == 0) return (arr[0] == k);
    
    // First, consider not taking the current element
    bool not_take = f(ind - 1, k, arr);

    // Then, consider taking the current element if its value is less than or equal to k
    bool take = false;
    if (k >= arr[ind])
        take = f(ind - 1, k - arr[ind], arr);

    return take || not_take;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Call the recursive function with the last index (n - 1) and k
    return f(n - 1, k, arr);
}









bool f(int ind, int k, vector<int> &arr,vector<vector<int>>&dp) {
    if (k == 0) return true;
    if (ind == 0) return (arr[0] == k);
    if (dp[ind][k]!=-1) return dp[ind][k];

    // First, consider not taking the current element
    bool not_take = f(ind - 1, k, arr,dp);

    // Then, consider taking the current element if its value is less than or equal to k
    bool take = false;
    if (k >= arr[ind])
        take = f(ind - 1, k - arr[ind], arr,dp);

    return dp[ind][k]= take | not_take;
}

bool subsetSumToK(int n, int k,vector<int> &arr) {
    // Call the recursive function with the last index (n - 1) and k
     vector<vector<int>>dp(n,vector<int>(k+1,-1));
    return f(n - 1, k, arr,dp);
}










bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

    // Base cases: If sum = 0, then it's always possible to achieve it by not taking any element.
    for (int i = 0; i < n; i++)
        dp[i][0] = true;

    // If the first element of the array equals the required sum, it's possible to achieve it.
        dp[0][arr[0]] = true;

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= k; j++) {
            bool not_take = dp[i - 1][j]; // Consider not taking the current element.
            bool take = false; // Initialize take as false.

            // If the current element can contribute to the sum and considering taking it.
            if (j >= arr[i])
                take = dp[i - 1][j - arr[i]];

            dp[i][j] = take || not_take; // Store the result for the current subproblem.
        }
    }

    return dp[n - 1][k]; // The final result is stored in dp[n-1][k].
}











bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<bool>prev(k+1,false), cur(k+1,false);
    // Base cases: If sum = 0, then it's always possible to achieve it by not taking any element.
    for (int i = 0; i < n; i++)
        prev[0]=cur[0] = true;
        prev[arr[0]] = true;

    for (int i = 1; i < n; i++) {
        cur[0] = true;
        for (int j = 1; j <= k; j++) {
            bool not_take = prev[j]; // Consider not taking the current element.
            bool take = false; // Initialize take as false.

            // If the current element can contribute to the sum and considering taking it.
            if (j >= arr[i])
                take = prev[j - arr[i]];

            cur[j] = take || not_take; // Store the result for the current subproblem.
        }
        prev = cur;
    }

    return prev[k]; // The final result is stored in dp[n-1][k].
}
