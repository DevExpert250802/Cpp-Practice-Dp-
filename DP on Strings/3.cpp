Longest Common Substring





#include <bits/stdc++.h>
int lcs(string &s, string &t){
	int n=s.size();
	int m=t.size();
  int ans=0;
	vector<vector<int>>dp(n+1,vector<int>(m+1,0));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
      if (s[i - 1] == t[j - 1]) {
        dp[i][j] = 1 + dp[i - 1][j - 1];
        ans = max(ans, dp[i][j]);
      } else dp[i][j] = 0;
    }
  }
	return ans;		 
}






TC = O(n*m) | SC = O(n*m)






#include <bits/stdc++.h>
int lcs(string &s, string &t){
	int n=s.size();
	int m=t.size();
  int ans=0;
	vector<int>prev(m+1,0),cur(m+1,0);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
      if (s[i - 1] == t[j - 1]) {
        cur[j] = 1 + prev[j - 1];
        ans = max(ans, cur[j]);
      } else cur[j] = 0;
    }
    prev=cur;
  }
	return ans;		 
}



TC = O(n*m) | SC = O(m)
