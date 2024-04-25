Wildcard Pattern Matching


#include<bits/stdc++.h>
bool f(int i, int j,string&s1, string&s2){

   if(i<0&&j<0) return true; // both over
   if(i<0&&j>=0) return false; // string 1 over and 2 remained
   if(j<0 && i>=0) {
        for(int t=0; t<=i; t++){
            if (s1[t] != '*') {
                return false;
            }
        }
        return true;
    }

   if(s1[i]==s2[j] || s1[i]== '?')  return f(i-1,j-1,s1,s2);
   if(s1[i]== '*' ) return f(i-1,j,s1,s2) || f(i,j-1,s1,s2);  //Matches any sequence of characters
   return false;
}

bool wildcardMatching(string pattern, string text){
   int n= pattern.size();
   int m=text.size();
  return f(n-1,m-1,pattern,text);
}












#include<bits/stdc++.h>
bool f(int i, int j,string&s1, string&s2,vector<vector<int>>dp){

   if(i<0&&j<0) return true; // both over
   if(i<0&&j>=0) return false; // string 1 over and 2 remained
   if(j<0 && i>=0) {
        for(int t=0; t<=i; t++){
            if (s1[t] != '*') {
                return false;
            }
        }
        return true;
    }
    if(dp[i][j]!=-1) return dp[i][j];

   if(s1[i]==s2[j] || s1[i]== '?')  return dp[i][j]= f(i-1,j-1,s1,s2,dp);
   if(s1[i]== '*' ) return dp[i][j]= f(i-1,j,s1,s2,dp) || f(i,j-1,s1,s2,dp);  //Matches any sequence of characters
   return false;
}

bool wildcardMatching(string pattern, string text){
   int n= pattern.size();
   int m=text.size();
   vector<vector<int>>dp(n,vector<int>(m,-1));
  return f(n-1,m-1,pattern,text,dp);
}








#include<bits/stdc++.h>
bool f(int i, int j,string&s1, string&s2,vector<vector<int>>dp){

   if(i==0 && j==0) return true; // both over
   if(i==0 && j>0) return false; // string 1 over and 2 remained
   if(j==0 && i>0) {
        for(int t=1; t<=i; t++){
            if (s1[t-1] != '*') {
                return false;
            }
        }
        return true;
    }
    if(dp[i][j]!=-1) return dp[i][j];

   if(s1[i-1]==s2[j-1] || s1[i-1]== '?')  return dp[i][j]= f(i-1,j-1,s1,s2,dp);
   if(s1[i-1]== '*' ) return dp[i][j]= f(i-1,j,s1,s2,dp) || f(i,j-1,s1,s2,dp);  //Matches any sequence of characters
   return false;
}

bool wildcardMatching(string pattern, string text){
   int n= pattern.size();
   int m=text.size();
   vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
  return f(n,m,pattern,text,dp);
}













#include<bits/stdc++.h>
bool wildcardMatching(string s1, string s2){
   int n= s1.size();
   int m=s2.size();
   vector<vector<bool>>dp(n+1,vector<bool>(m+1,false));

  dp[0][0]=true;
  for(int j=1;j<=m;j++) dp[0][j]=false;  // string 1 over and 2 remained

  for(int i=1;i<=n;i++){
        bool flag=true;
        for(int t=1; t<=i; t++){
            if (s1[t-1] != '*') {
                flag=false;
                break;
            }
        }
        dp[i][0] = flag;
  }


   for(int i=1;i<=n;i++){
       for(int j=1;j<=m;j++){
              if(s1[i-1] == s2[j-1]  ||  s1[i-1] == '?')   dp[i][j]= dp[i-1][j-1];
             else if(s1 [i-1] == '*' )  dp[i][j] = dp[i-1][j] |  dp[i][j-1];  //Matches any sequence of characters
             else dp[i][j]=false;
        }
    }
   return dp[n][m];
   }










#include<bits/stdc++.h>
bool wildcardMatching(string s1, string s2){
   int n= s1.size();
   int m=s2.size();
   vector<bool>prev(m+1,false),cur(m+1,false);
   prev[0]=true;
  for(int j=1;j<=m;j++) prev[j]=false;  // string 1 over and 2 remained

   for(int i=1;i<=n;i++){
 // cur is current row/s column
 // and that cur's 0th row has to be assigned everytime
         bool flag=true;
         for(int t=1; t<=i; t++){
            if (s1[t-1] != '*') {
                flag=false;
                break;
            }
        }
        cur[0] = flag;
       for(int j=1;j<=m;j++){
              if(s1[i-1] == s2[j-1]  ||  s1[i-1] == '?')   cur[j]= prev[j-1];
             else if(s1 [i-1] == '*' )  cur[j] = prev[j] |  cur[j-1];  //Matches any sequence of characters
             else cur[j]=false;
        }
        prev=cur;
    }
   return prev[m];
   }




