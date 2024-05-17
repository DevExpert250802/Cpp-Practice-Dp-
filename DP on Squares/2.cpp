Count Square Submatrices with All 1s 

 Given an n * m matrix of ones and zeros, return how many square submatrices have all ones



Example 1:
Input: matrix = [ [0,1,1,1],
[1,1,1,1],
[0,1,1,1]]
Output: 15
Explanation: 
There are 10 squares of size 1.
There are 4 squares of size 2.
There is  1 square of size 3.
Total number of squares = 10 + 4 + 1 = 15.

Example 2:
Input: matrix =  [ [1,0,1],
[1,1,0],
[1,1,0]]
Output: 7
Explanation: 
There are 6 squares of size 1.  
There is 1 square of size 2. 
Total number of squares = 6 + 1 = 7.







#include <bits/stdc++.h>
using namespace std;

int countSquares(int n, int m, vector<vector<int>> &arr) {
    vector<vector<int>> dp(n, vector<int>(m, 0));

    for (int j = 0; j < m; j++) dp[0][j] = arr[0][j];
    for (int i = 0; i < n; i++) dp[i][0] = arr[i][0];

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (arr[i][j] == 0) dp[i][j] = 0;
            else {
                dp[i][j] = 1 + min(dp[i - 1][j],
                                   min(dp[i - 1][j - 1], dp[i][j - 1]));
            }
        }
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            sum += dp[i][j];
        }
    }
    return sum;
}

int main() {

    vector<vector<int>> arr = {
        {0, 1, 1, 1}, {1, 1, 1, 1},
        {0, 1, 1, 1}
    };
    int n = 3, m = 4;
    int squares = countSquares(n, m, arr);
    cout << "The number of squares: " << squares << "\n";
    return 0;
}



  
