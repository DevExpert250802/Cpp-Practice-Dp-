//Approach-1 (Recursion)
//T.C : O(2^n)
//S.C : O(n)
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


