/*                                                       Students Happiness

Description :                                                
There are N Ranks and M students in a class. Each student has a happiness value for the rank in the class he gets. The i th Student gets happy[i][j] on getting a rank j. 
It's ok to not keep all students in the ranks (They get 0 happiness). At most one student can be assigned to a rank.
The total happiness of the assignment can be calculated as Sum of Happiness of each of the students in the class. Find the best way to calculate.

The first line of each test case contains two space-separated integers N, M. 1 ≤ N ≤ 10, 1 ≤ M ≤ 50.

The next M lines contain N integers, 0 ≤ happy[i][j] ≤ 10^5.



  */




#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
int happy[50][10];
int dp[50][(1<<10)];
int n, m;
 
int dfs(int pos, int vis) {
    if(pos == m) {
        return 0;
    }
    if(dp[pos][vis] != -1) {
        return dp[pos][vis];
    }
    int ans = dfs(pos+1, vis);
    for (int i = 0; i < n; ++i) {
        if((vis & (1<<i)) == 0) {
            int temp = happy[pos][i] + dfs(pos+1, vis | (1<<i));
            ans = max(ans, temp);
        }
    }
    dp[pos][vis] = ans;
    return ans;
}
 
signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < (1<<n); ++j) {
                dp[i][j] = -1;
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> happy[i][j];
            }
        }
        cout << dfs(0, 0) << "\n";
    }
    return 0;
}








Time Complexity case: O(M * N * 2^N)


