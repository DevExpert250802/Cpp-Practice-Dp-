 Edit Distance




Problem statement
You are given two strings 'S' and 'T' of lengths 'N' and 'M' respectively. Find the "Edit Distance" between the strings.

Edit Distance of two strings is the minimum number of steps required to make one string equal to the other. In order to do so, you can perform the following three operations:

1. Delete a character
2. Replace a character with another one
3. Insert a character









#include <bits/stdc++.h>
int f(string& s1, string& s2, int i, int j) {
    if (i < 0) return j + 1;
    if (j < 0)return i + 1;
    if (s1[i] == s2[j])
        return  f(s1, s2, i-1, j-1);
    else  //  Delete    Replace    Insert 
    return 1 + min({f(s1, s2,i-1,j),f(s1, s2,i -1,j-1),f(s1, s2, i, j - 1)});
}

int editDistance(string& S1, string& S2) {
    int n = S1.size();
    int m = S2.size();
    return f(S1, S2, n - 1, m - 1);
}







#include <bits/stdc++.h>
int f(string& s1, string& s2, int i, int j,vector<vector<int>>&dp) {
    if (i < 0) return j + 1;
    if (j < 0)return i + 1;
    if(dp[i][j]!=-1)return dp[i][j];
    if (s1[i] == s2[j])
        return  dp[i][j]= f(s1, s2, i-1, j-1,dp);
    else  //  Delete    Replace    Insert 
    return dp[i][j] = 1 + min({f(s1, s2,i-1,j,dp),f(s1, s2,i -1,j-1,dp),f(s1, s2, i, j - 1,dp)});
}

int editDistance(string& S1, string& S2) {
    int n = S1.size();
    int m = S2.size();
    vector<vector<int>>dp(n,vector<int>(m,-1));
    return f(S1, S2, n-1, m-1,dp);
}







#include <bits/stdc++.h>
int f(string& s1, string& s2, int i, int j,vector<vector<int>>&dp) {
    if (i == 0) return j ;
    if (j == 0)return i ;
    if(dp[i][j]!=-1)return dp[i][j];
    if (s1[i-1] == s2[j-1])
        return  dp[i][j]= f(s1, s2, i-1, j-1,dp);
    else  //  Delete    Replace    Insert 
    return dp[i][j] = 1 + min({f(s1, s2,i-1,j,dp),f(s1, s2,i -1,j-1,dp),f(s1, s2, i, j - 1,dp)});
}

int editDistance(string& S1, string& S2) {
    int n = S1.size();
    int m = S2.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    return f(S1, S2, n,m,dp);
}





#include <bits/stdc++.h>
int editDistance(string& s1, string& s2) {
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int j=0;j<=m;j++) dp[0][j] =j;
    for(int i=0;i<=n;i++) dp[i][0]=i;
     
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if (s1[i-1] == s2[j-1])
         dp[i][j]= dp[ i-1][j-1];
          else  //  Delete    Replace    Insert
         dp[i][j] = 1 + min({dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]});
        }
    }
    return dp[n][m];
}








#include <bits/stdc++.h>
int editDistance(string& s1, string& s2) {
    int n = s1.size();
    int m = s2.size();
    vector<int>prev(m+1,0),cur(m+1,0);
    for(int j=0;j<=m;j++) prev[j] =j;
     
    for(int i=1;i<=n;i++){
        cur[0]=i;
        for(int j=1;j<=m;j++){
            if (s1[i-1] == s2[j-1])
              cur[j]= prev[j-1];
            else  //  Delete    Replace    Insert
              cur[j] = 1 + min({prev[j], prev[j - 1], cur[j - 1]});
        }
        prev=cur;
    }
    return prev[m];
}
