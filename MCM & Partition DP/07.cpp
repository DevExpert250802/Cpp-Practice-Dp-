/*
    Company Tags : GOOGLE
    Leetcode Link : https://leetcode.com/problems/scramble-string/
*/

// Appoach-1 (Recursion)

class Solution {
public:
   bool f(string s1, string s2){
    
    if(s1.size()==1) return s1==s2;
    if(s1.length()!= s2.length())return false;

    bool result = false;
    int n = s1.length();

    for(int i=0;i<n;i++){
        bool swapped= f(s1.substr(0,i),s2.substr(n-i,i)) && f(s1.substr(i,n-i),s2.substr(0,n-i));
          if(swapped){
             result = true; 
             break;
            }
        bool not_swapped= f(s1.substr(0,i),s2.substr(0,i)) && f(s1.substr(i,n-i),s2.substr(i,n-i));
            if(not_swapped){
               result = true; 
              break;
            }
        }
     
        return result;
   }
    bool isScramble(string s1, string s2) {
        return f(s1,s2);
    }
};


// substr(index,length)


Time complexity: O(4^n)
Space Complexity: O(n)



// Appoach-2 (Recursion + Memo)


  

/*  s1= pacdef|abcd    s2= |abcd   if match I do not check again and again   

The unordered map (mp) is used to store the results of subproblems to:

Avoid redundant calculations.
Improve efficiency by reusing previously computed results.

*/ 


  

class Solution {
public:
  unordered_map<string,bool>mp;
   bool f(string s1, string s2){
    
    if(s1.size()==1) return s1==s2;
    if(s1.length()!= s2.length())return false;

    string key = s1+"_"+s2;

    if(mp.find(key) != mp.end()) return mp[key];

    bool result = false;
    int n = s1.length();

    for(int i=0;i<n;i++){
        bool swapped= f(s1.substr(0,i),s2.substr(n-i,i)) && f(s1.substr(i,n-i),s2.substr(0,n-i));
          if(swapped){
             result = true; 
             break;
            }
        bool not_swapped= f(s1.substr(0,i),s2.substr(0,i)) && f(s1.substr(i,n-i),s2.substr(i,n-i));
            if(not_swapped){
               result = true; 
              break;
            }
        }
        return mp[key]= result;
   }
    bool isScramble(string s1, string s2) {
        mp.clear();
        return f(s1,s2);
    }
};







class Solution {
public:
    unordered_map<string, bool> mp;

    bool f(const string& s1, const string& s2) {
        if (s1.size() != s2.size()) return false;
        if (s1 == s2) return true;
        if (s1.size() <= 1) return false;

        string key = s1 + "_" + s2;
        if (mp.find(key) != mp.end()) return mp[key];

        int n = s1.size();
        bool result = false;

        for (int i = 1; i < n; i++) {
            bool swapped = f(s1.substr(0, i), s2.substr(n - i)) && f(s1.substr(i), s2.substr(0, n - i));
            bool not_swapped = f(s1.substr(0, i), s2.substr(0, i)) && f(s1.substr(i), s2.substr(i));

            if (swapped || not_swapped) {
                result = true;
                break;
            }
        }

        return mp[key] = result;
    }

    bool isScramble(string s1, string s2) {
        mp.clear();
        return f(s1, s2);
    }
};


Time complexity: O(n^4)
O(n) = O(n)+O(n)+O(n) ==> split string ,merge split string, analyze split string 
O(n*n)  = split string has two parts => left part goes to n depth & right part goes to n depth  and when they come back their resultant get multiplied to get possible string 
O(n) = and there are n string


Space complexity: O(n^3)
