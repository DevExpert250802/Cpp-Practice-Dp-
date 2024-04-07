int f(int ind, int N,vector<int> &price){
	if(ind==0){
		return N*price[0];
	}
	
	int notTake =0+f(ind-1,N,price);
	int Take = INT_MIN;
	int rodlength = ind+1;
	if(rodlength<=N)Take= price[ind]+f(ind,N-rodlength,price);
	return max(Take,notTake);
}
int cutRod(vector<int> &price, int n){
	return f(n-1,n,price);
}








int f(int ind, int N,vector<int> &price,vector<vector<int>>&dp){
	if(ind==0){
		return N*price[0];
	}
	if(dp[ind][N] != -1)return dp[ind][N];
	int notTake =0+f(ind-1,N,price,dp);
	int Take = INT_MIN;
	int rodlength = ind+1;
	if(rodlength<=N)Take= price[ind]+f(ind,N-rodlength,price,dp);
	return dp[ind][N] =max(Take,notTake);
}
int cutRod(vector<int> &price, int n){
	vector<vector<int>>dp(n,vector<int>(n+1,-1));
	return f(n-1,n,price,dp);
}







int cutRod(vector<int> &price, int n){

  vector<vector<int>>dp(n,vector<int>(n+1,0));

    for(int N=0; N<=n; N++){
		dp[0][N] = N*price[0];
	}
	for(int ind=1;ind<n;ind++){
       for(int N=0;N<=n; N++){
			int notTake =dp[ind-1][N];
			int Take = INT_MIN;
			int rodlength = ind+1;
			if(rodlength<=N)Take= price[ind]+dp[ind][N-rodlength];
			 dp[ind][N] =max(Take,notTake);
	   }
	}
    return dp[n-1][n];
}










int cutRod(vector<int> &price, int n){

  vector<int>prev(n+1,0),cur(n+1,0);

    for(int N=0; N<=n; N++){
		prev[N] = N*price[0];
	}
	for(int ind=1;ind<n;ind++){
       for(int N=0;N<=n; N++){
			int notTake =prev[N];
			int Take = INT_MIN;
			int rodlength = ind+1;
			if(rodlength<=N)Take= price[ind]+cur[N-rodlength];
			 cur[N] =max(Take,notTake);
	   }
	   prev=cur;
	}
    return prev[n];
}








int cutRod(vector<int> &price, int n){

  vector<int>prev(n+1,0);

    for(int N=0; N<=n; N++){
		prev[N] = N*price[0];
	}
	for(int ind=1;ind<n;ind++){
       for(int N=0;N<=n; N++){
			int notTake =prev[N];
			int Take = INT_MIN;
			int rodlength = ind+1;
			if(rodlength<=N)Take= price[ind]+prev[N-rodlength];
			 prev[N] =max(Take,notTake);
	   }
	}
    return prev[n];
}

