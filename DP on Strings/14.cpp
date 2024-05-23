//Approach-1 (Recursion)
//T.C : O((2^n)∗w))
//S.C : O(n*w)
class Solution {
public:
    bool duplicate(string&s1,string&s2){
        int arr[26] = {0};
        for(char &ch: s1){
           if(arr[ch-'a']>0) return true;
            arr[ch-'a']++;
        }
        for(char &ch: s2){
            if(arr[ch-'a']>0) return true;
        }
        return false;
    }
    int f(int ind,vector<string>& arr,string temp,int n){
        if(ind==n)return temp.length();
        int take=0,not_take=0;
        if(duplicate(arr[ind],temp)){
            not_take = f(ind+1,arr,temp,n);
        }
        else{
            not_take = f(ind+1,arr,temp,n);
            take     = f(ind+1,arr,temp + arr[ind],n);
        }
        return max(take,not_take);
    }
    int maxLength(vector<string>& arr) {
        string temp="";
        int n = arr.size();
        return f(0,arr,temp,n);
    }
};




//Approach-2 (Bit Manipulation + DFS )
//T.C : O(2^n)
//S.C : O(n)


class Solution {
public:
      void dfs(int idx, int temp, int &result, vector<int>& uniqueCharStrings) {
          
            result = max(result, __builtin_popcount(temp));
          
            for (int i = idx; i < uniqueCharStrings.size(); i++) {
                
                if ((temp & uniqueCharStrings[i]) == 0) { //means no unique characters in temp and uniqueCharStrings[i]
                    //So concatenate them : temp | uniqueCharStrings[i]
                    
                    dfs(i + 1, temp | uniqueCharStrings[i], result, uniqueCharStrings);
                    
                }
            }
      }
    
      int maxLength(vector<string>& arr) {
        vector<int> uniqueCharStrings;

        for (string &s : arr) {
            unordered_set<char> st(begin(s), end(s));
            
            if (st.size() != s.length())  //means they have duplicates
                continue;
            
            int val = 0; //Store the string in form of a number (binary)
            for (char &ch : s) 
                val |= 1 << (ch - 'a');
            
            uniqueCharStrings.push_back(val);
        }

        int result = 0; //This will store the longest 
        dfs(0, 0, result, uniqueCharStrings);
        return result;
    }
};

