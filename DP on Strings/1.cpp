Longest Common Subsequence



// Recursion


#include <bits/stdc++.h>

int f(int i,int j,string&s,string&t){
   if(i<0 || j<0) return 0;

	if(s[i]==t[j]) return 1+f(i-1,j-1,s,t);

	return 0+max( f(i-1,j,s,t),f(i,j-1,s,t));
}

int lcs(string s, string t){
int n= s.length();
int m= t.length();
return  f(n-1,m-1,s,t);
}






// Memorization



#include <bits/stdc++.h>

int f(int i,int j,string&s,string&t,vector<vector<int>>&dp){
   if(i<0 || j<0) return 0;
    if(dp[i][j] != -1) return dp[i][j];
	if(s[i]==t[j]) return dp[i][j] =1+f(i-1,j-1,s,t,dp);

	return dp[i][j] =0+max( f(i-1,j,s,t,dp),f(i,j-1,s,t,dp));
}

int lcs(string s, string t){
int n= s.length();
int m= t.length();
vector<vector<int>>dp(n,vector<int>(m,-1));
return  f(n-1,m-1,s,t,dp);
}



// shifting of index 



int f(int i,int j,string&s,string&t,vector<vector<int>>&dp){
   if(i==0 || j==0) return 0;
    if(dp[i][j] != -1) return dp[i][j];
	if(s[i-1]==t[j-1]) return dp[i][j] =1+f(i-1,j-1,s,t,dp);

	return dp[i][j] =0+max( f(i-1,j,s,t,dp),f(i,j-1,s,t,dp));
}

int lcs(string s, string t){
int n= s.length();
int m= t.length();
vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
return  f(n,m,s,t,dp);
}







// Tabulation



int lcs(string s, string t){
int n= s.length();
int m= t.length();
vector<vector<int>>dp(n+1,vector<int>(m+1,0));

for(int j=0;j<=m;j++) dp[0][j]=0;
for(int i=0;i<=n;i++) dp[i][0]=0;

for(int i=1;i<=n;i++){
	for(int j=1;j<=m;j++){
		if(s[i-1]==t[j-1])  dp[i][j] =1+dp[i-1][j-1];
	   else dp[i][j] =0+max( dp[i-1][j] , dp[i][j-1]);
	}
}
	return dp[n][m];
}







// Space optimization



int lcs(string s, string t){
int n= s.length();
int m= t.length();
vector<int>prev(m+1,0),cur(m+1,0);

for(int j=0;j<=m;j++) prev[j]=0;

for(int i=1;i<=n;i++){
	for(int j=1;j<=m;j++){
		if(s[i-1]==t[j-1])  cur[j] =1+prev[j-1];
	   else cur[j] =0+max( prev[j] , cur[j-1]);
	}
	prev=cur;
}
	return prev[m];
}



