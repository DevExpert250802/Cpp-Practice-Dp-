 Distinct Subsequences




int f(int i,int j,string&s1,string&s2){
	if(j<0) return 1;
	if(i<0) return 0;
	if(s1[i]==s2[j]) return f(i-1,j,s1,s2) + f(i-1,j-1,s1,s2);
        else
	return f(i-1,j,s1,s2);
}
int distinctSubsequences(string &str, string &sub){
	int n=str.size();
	int m=sub.size();
	return f(n-1,m-1,str,sub);

}




int mod =1e9+7;
int f (int i,int j,string &s1,string& s2,vector<vector<int>>&dp){
	if(j<0) return 1;
	if(i<0) return 0;
	if(dp[i][j] != -1) return dp[i][j];
	if(s1[i]==s2[j]){
	 return dp[i][j] = ( f(i-1,j,s1,s2,dp) + f(i-1,j-1,s1,s2,dp) )%mod;
	}
	return dp[i][j] = f(i-1,j,s1,s2,dp)%mod;
}
int distinctSubsequences(string &str, string &sub){
	int n=str.size();
	int m=sub.size();
	vector<vector<int>>dp(n,vector<int>(m,-1));
	return f(n-1,m-1,str,sub,dp);

}





int mod =1e9+7;
int f (int i,int j,string &s1,string& s2,vector<vector<int>>&dp){
	if(j==0) return 1;
	if(i==0) return 0;
	if(dp[i][j] != -1) return dp[i][j];
	if(s1[i-1]==s2[j-1]){
	 return dp[i][j] = ( f(i-1,j,s1,s2,dp) + f(i-1,j-1,s1,s2,dp) )%mod;
	}
	return dp[i][j] = f(i-1,j,s1,s2,dp)%mod;
}
int distinctSubsequences(string &str, string &sub){
	int n=str.size();
	int m=sub.size();
	vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
	return f(n,m,str,sub,dp);
}





int mod =1e9+7;
int distinctSubsequences(string &s1, string &s2){
	int n=s1.size();
	int m=s2.size();
	vector<vector<int>>dp(n+1,vector<int>(m+1,0));
	for(int i=0;i<=n;i++) dp[i][0]=1;
	for(int j=1;j<=m;j++) dp[0][j]=0;

	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
		  if(s1[i-1]==s2[j-1]){
	        dp[i][j] = (dp[i-1][j] + dp[i-1][j-1] )%mod;
	        }
	      else dp[i][j] = dp[i-1][j]%mod;
		}
	}
	return dp[n][m];
}









int mod =1e9+7;
int distinctSubsequences(string &s1, string &s2){
	int n=s1.size();
	int m=s2.size();
	vector<int>prev(m+1,0),cur(m+1,0);
	prev[0]= cur[0]=1;

	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
		  if(s1[i-1]==s2[j-1]){
	        cur[j] = (prev[j] + prev[j-1] )%mod;
	        }
	      else cur[j] = prev[j]%mod;
		}
		prev=cur;
	}
	return prev[m];
}








int mod =1e9+7;
int distinctSubsequences(string &s1, string &s2){
	int n=s1.size();
	int m=s2.size();
	vector<int>prev(m+1,0);
	prev[0]=1;

	for(int i=1;i<=n;i++){
		for(int j=m;j>=1;j--){
		  if(s1[i-1]==s2[j-1]){
	        prev[j] = (prev[j] + prev[j-1] )%mod;
	        }
	      else prev[j] = prev[j]%mod;
		}
	}
	return prev[m];
}
