/*
    Company Tags: META
    Leetcode Link: https://leetcode.com/problems/valid-parenthesis-string/
*/

/*************************************************************** C++ ***************************************************************/
//Approach-1 (Using Recursion ) 
//T.C : O(3^n)
//S.C : O(n)

class Solution {
public:
    bool solve(int i ,int open,string&s){
        if(i==s.size()) return open==0;

        bool isValid = false;
        if(s[i]=='*'){
        isValid |= solve(i+1,open+1,s);
        if(open>0)
        isValid |= solve(i+1,open-1,s);
        isValid |= solve(i+1,open,s);
        }
        else if(s[i]=='('){
        isValid |= solve(i+1,open+1,s);
        }
        else{
            if(open>0)
        isValid |= solve(i+1,open-1,s);
        }
        return isValid;
    }
    bool checkValidString(string s) {
        return solve(0,0,s);
    }
};



//Approach-2 (Using Recrusion + Memoization) -> Why DP ? (See my video above)
//T.C : O(n*n)
//S.C : O(n*n) + O(n)

class Solution {
public:
    bool solve(int i ,int open,string&s,vector<vector<int>>&dp){
        if(i==s.size()) return open==0;
          
          if(dp[i][open]!=-1) return dp[i][open];

        bool isValid = false;
        if(s[i]=='*'){
        isValid |= solve(i+1,open+1,s,dp);
        if(open>0)
        isValid |= solve(i+1,open-1,s,dp);
        isValid |= solve(i+1,open,s,dp);
        }
        else if(s[i]=='('){
        isValid |= solve(i+1,open+1,s,dp);
        }
        else{
            if(open>0)
        isValid |= solve(i+1,open-1,s,dp);
        }
        return dp[i][open] =isValid;
    }
    bool checkValidString(string s) {
        vector<vector<int>>dp(s.size(),vector<int>(s.size(),-1));
        return solve(0,0,s,dp);

    }
};



//Approach-3 (Using Bottom Up)
//T.C : O(n*n)
//S.C : O(n*n)

class Solution {
public: 
    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, false));
        //State Definition :
        //t[i][j] = if the string from index i to n-1 is valid or not having j open brackets
        dp[n][0] = true;

        for (int i = n - 1; i >= 0; i--) {
            for (int open = 0; open <= n; open++) {
                bool isValid = false;

                if (s[i] == '*') {
                    isValid |= dp[i + 1][open + 1]; //Treating * as ( --> solve(i+1, open+1)
                    if (open > 0) {
                        isValid |= dp[i + 1][open - 1]; //Treating * as ) --> solve(i+1, open-1)
                    }
                    isValid |= dp[i + 1][open]; //Treating * as empty --> solve(i+1, open)
                } else {
                    if (s[i] == '(') {
                        isValid |= dp[i + 1][open + 1]; //solve(i+1, open+1)
                    } else if (open > 0) {
                        isValid |= dp[i + 1][open - 1]; //solve(i+1, open=-1)
                    }
                }
                dp[i][open] = isValid;
            }
        }

        return dp[0][0];
    }
};



//Approach-5 (Space Optimized) 
//T.C : O(n*n)
//S.C : O(n)


class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size(); 
        vector<bool> cur(n+1, 0), ahead(n+1, 0);
        ahead[0] = 1;

        for (int ind = n - 1; ind >= 0; ind--) {
            for (int open = 0; open <= n; open++) {
                bool isValid = false;
                if (s[ind] == '*') {
                      isValid |= ahead[open + 1];
                    if (open > 0) isValid |= ahead[open - 1];
                    isValid |= ahead[open];
                } else if (s[ind] == '(') {
                   isValid |= ahead[open + 1];
                } else if (s[ind] == ')') {
                    if (open > 0) isValid |= ahead[open - 1];
                }
                cur[open] = isValid;
            }
            ahead = cur;
        }

        return ahead[0];
    }
};

//Approach-5 (Using two Stacks) - No DP required
//T.C : O(n)
//S.C : O(n)
class Solution {
public: 
    bool checkValidString(string s) {
        stack<int> openSt;
        stack<int> asterisksSt;

        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];

            if (ch == '(') {
                openSt.push(i);
            } else if (ch == '*') {
                asterisksSt.push(i);
            } else {
                if (!openSt.empty()) {
                    openSt.pop();
                } else if (!asterisksSt.empty()) {
                    asterisksSt.pop();
                } else {
                    return false;
                }
            }
        }

        //This post-processing will be required for cases like - "*(())(*"
        while (!openSt.empty() && !asterisksSt.empty()) {
            if (openSt.top() > asterisksSt.top()) {
                return false;
            }
            openSt.pop();
            asterisksSt.pop();
        }

        return openSt.empty();
    }
};


//Approach-4 (Constant Space)
//T.C : O(n)
//S.C :O(1)
//NOTE: You can easily combine both loops in just a single for loop. I have written them separately for the sake of simplicity and understanding
class Solution {
public:
    bool checkValidString(string s) {
        int open = 0;
        int close = 0;
        int n = s.length();
        
        //Left to Right - Check Open Brackets
        for (int i = 0; i < n; i++) {

            if (s[i] == '(' || s[i] == '*') {
                open++;
            } else {
                open--;
            }
                
            if (open < 0) {
                return false;
            }
        }

        //Right to Left - Check CLose Brackets
        for (int i = n - 1; i >= 0; i--) {
            
            if (s[i] == ')' || s[i] == '*') {
                close++;
            } else {
                close--;
            }
            
            
            if (close < 0) {
                return false;
            }
        }
        
        return true;
    }
};
