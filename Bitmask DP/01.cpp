/*              https://maang.in/problems/Students-Happiness-452?resourceUrl=cs74-cp487-pl3292-rs452

                                                       Students Happiness
Description :
There are N Ranks and M students in a class. Each student has a happiness value for the rank in the class he gets. The i th Student gets happy[i][j] on getting a rank j.
It's ok to not keep all students in the ranks (They get 0 happiness). At most one student can be assigned to a rank. 
The total happiness of the assignment can be calculated as Sum of Happiness of each of the students in the class. Find the best way to calculate.

Input Format:
The first line contains an integer T (1 ≤ T ≤ 200) - the number of testcases.
The first line of each test case contains two space-separated integers N, M. 1 ≤ N ≤ 10, 1 ≤ M ≤ 50.
The next M lines contain N integers, 0 ≤ happy[i][j] ≤ 10^5.

Output Format:
For each test case print the maximum sum of happiness possible in a new line.


Constraints
Sample Input 1
4
6 11
49 78 23 100 29 2
11 28 39 27 77 45
24 52 18 45 84 41
85 88 75 21 98 100
59 24 27 21 94 90
88 0 0 16 89 54
63 24 100 23 18 75
26 34 54 14 28 11
68 61 40 14 67 14
16 62 17 70 29 52
97 53 0 98 90 75 
1 2
8
6 
5 9
6 0 7 9 3
10 0 1 1 4
0 2 4 6 1
7 1 5 5 10
0 3 3 1 10
9 8 6 9 1
0 10 6 0 2
4 9 2 4 9
4 10 10 3 7 
4 5
10 2 4 0
10 1 6 7
6 3 2 0
2 3 5 1
10 4 7 6 

Sample Output 1 :
564
8
49
27

 */





/*
TestCase  explanation :
4 5             n = 4 (ranks)    m=5 (students)
10 2 4 0        => 10 (1st)
10 1 6 7        =>  7 (4th)
6 3 2 0         =>  3 (2nd)
2 3 5 1
10 4 7 6        => 7  (3rd)

10+7+7+3= 27



5 9
6 0 7 9 3       
10 0 1 1 4        => 10 (1st)
0 2 4 6 1
7 1 5 5 10        => 10 (5th)
0 3 3 1 10
9 8 6 9 1         => 9  (4th)
0 10 6 0 2        => 10 (2nd)
4 9 2 4 9
4 10 10 3 7       => 10 (3rd)

10+10+9+10+10  = 49

*/




#include <bits/stdc++.h>
using namespace std;

int f(int i, int mask, int n, int m,  vector<vector<int>>& happy, vector<vector<int>>& dp) {
    if (i == m) return 0;
    if (dp[i][mask] != -1) return dp[i][mask];

    int ans = f(i + 1, mask, n, m, happy, dp);
    for (int j = 0; j<n; j++) {
        
        if ((mask & (1 << j)) == 0) {
            int temp =  happy[i][j] + f(i+1, mask | (1 << j), n, m,happy,dp );
            ans = max(ans,temp);
        }
    }
    return dp[i][mask] = ans;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> happy(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> happy[i][j];
            }
        }

        vector<vector<int>> dp(m, vector<int>(1 << n, -1));
        cout << f(0, 0, n, m, happy, dp) << endl;
    }
    return 0;
}









Time Complexity case: O(M * N * 2^N)


