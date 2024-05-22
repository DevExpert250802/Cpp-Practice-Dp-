//Approach-1 (Using Recursion ) 
//T.C : O(2^n)
//S.C : O(n)


class Solution {
public:

int f(string &s, int curr_ind, int prev_val) {

    if (curr_ind == s.size()) return 0;

    int flip = INT_MAX , noflip = INT_MAX;

    if (s[curr_ind] == '0') {
        if (prev_val == 0) {
            flip = 1 + f(s, curr_ind + 1, 1); // Flip current '0' to '1'
            noflip = f(s, curr_ind + 1, 0); // Don't flip current '0'
        }
         else {
            flip = 1 + f(s, curr_ind + 1, 1); // Flip current '0' to '1'
        }
    } 
        else if(s[curr_ind] == '1')
        {
            if(prev_val == 1) {
                noflip = f(s, curr_ind+1, 1);
            } else {
                 flip   = 1 + f(s, curr_ind+1, 0);
                noflip = f(s, curr_ind+1, 1);
            }
        }

    return  min(flip, noflip); 
}

int minFlipsMonoIncr(string s) {
    int n =s.length();
    return f(s, 0, 0);
}
};




//Approach-2 (Using Recrusion + Memoization) 
//T.C : O(n*n)
//S.C : O(n*2) + O(n)



class Solution {
public:

int f(string &s, int curr_ind, int prev_val,vector<vector<int>>&dp) {

    if (curr_ind == s.size()) return 0;

    int flip = INT_MAX , noflip = INT_MAX;

    if(dp[curr_ind][prev_val] != -1) return dp[curr_ind][prev_val];

    if (s[curr_ind] == '0') {
        if (prev_val == 0) {
            flip = 1 + f(s, curr_ind + 1, 1,dp); // Flip current '0' to '1'
            noflip = f(s, curr_ind + 1, 0,dp); // Don't flip current '0'
        }
         else {
            flip = 1 + f(s, curr_ind + 1, 1,dp); // Flip current '0' to '1'
        }
    } 
        else if(s[curr_ind] == '1')
        {
            if(prev_val == 1) {
                noflip = f(s, curr_ind+1, 1, dp);
            } else {
                 flip   = 1 + f(s, curr_ind+1, 0, dp);
                noflip = f(s, curr_ind+1, 1, dp);
            }
        }

    return dp[curr_ind][prev_val]= min(flip, noflip); 
}

int minFlipsMonoIncr(string s) {
    int n =s.length();
    vector<vector<int>>dp(n+1,vector<int>(2,-1));
    return f(s, 0, 0,dp);
}
};






//Approach-3 (Using Bottom Up)
//T.C : O(n*n)
//S.C : O(n*2)



class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.length();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        
        dp[n][0] = dp[n][1] = 0;

        // Iterate from the end of the string to the start
        for (int curr_ind = n - 1; curr_ind >= 0; curr_ind--) {
            for (int prev_val = 0; prev_val <= 1; prev_val++) {
                int flip = INT_MAX, noflip = INT_MAX;

                if (s[curr_ind] == '0') {
                    if (prev_val == 0) {
                        flip = 1 + dp[curr_ind + 1][1];  // Flip current '0' to '1'
                        noflip = dp[curr_ind + 1][0];   // Don't flip current '0'
                    } else {
                        flip = 1 + dp[curr_ind + 1][1];  // Flip current '0' to '1'
                    }
                } else if (s[curr_ind] == '1') {
                    if (prev_val == 1) {
                        noflip = dp[curr_ind + 1][1];   // Don't flip current '1'
                    } else {
                        flip = 1 + dp[curr_ind + 1][0];  // Flip current '1' to '0'
                        noflip = dp[curr_ind + 1][1];   // Don't flip current '1'
                    }
                }

                dp[curr_ind][prev_val] = min(flip, noflip);
            }
        }

        // Return the minimum flips needed starting with the previous value 0
        return dp[0][0];
    }
};



//Approach-4 (Space Optimized) 
//T.C : O(n*n)
//S.C : O(4)



class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.length();
         vector<int>cur(2, 0),ahead(2,0);
          ahead[0] = ahead[1] = 0;

         // Iterate from the end of the string to the start
        for (int curr_ind = n - 1; curr_ind >= 0; curr_ind--) {
            for (int prev_val = 0; prev_val <= 1; prev_val++) {
                int flip = INT_MAX, noflip = INT_MAX;

                if (s[curr_ind] == '0') {
                    if (prev_val == 0) {
                        flip = 1 + ahead[1];  // Flip current '0' to '1'
                        noflip = ahead[0];   // Don't flip current '0'
                    } else {
                        flip = 1 + ahead[1];  // Flip current '0' to '1'
                    }
                } else if (s[curr_ind] == '1') {
                    if (prev_val == 1) {
                        noflip = ahead[1];   // Don't flip current '1'
                    } else {
                        flip = 1 + ahead[0];  // Flip current '1' to '0'
                        noflip = ahead[1];   // Don't flip current '1'
                    }
                }

                cur[prev_val] = min(flip, noflip);
            }
            ahead=cur;
        }
        // Return the minimum flips needed starting with the previous value of 0
        return ahead[0];
    }
};








//Approach-5 (Constant Space)
//T.C : O(n)
//S.C :O(1)



class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int count_ones=0;
        int flips=0;
        for(char &ch : s){
            if(ch=='1')
            count_ones++;
            else{
                flips=min(flips+1,count_ones);
            }
        }
        return flips;
    }
};
