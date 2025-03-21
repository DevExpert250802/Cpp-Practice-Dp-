class Solution {
public:
    bool f(int cs, int pj, vector<int>& stones, unordered_map<int, int>& mp) {
        if (cs == stones.size() - 1)return true;
        int curr_pos = stones[cs];

        int next_jump = pj - 1;
        if (next_jump > 0) {
            int next_pos = curr_pos + next_jump;
            if (mp.find(next_pos) != mp.end()) {
                if (f(mp[next_pos], next_jump, stones, mp))return true;
            }
        }
      
        next_jump = pj;
        if (next_jump > 0) {
            int next_pos = curr_pos + next_jump;
            if (mp.find(next_pos) != mp.end()) {
                if (f(mp[next_pos], next_jump, stones, mp))return true;
            }
        }

        next_jump = pj + 1;
        int next_pos = curr_pos + next_jump;
        if (mp.find(next_pos) != mp.end()) {
            if (f(mp[next_pos], next_jump, stones, mp))return true;
        }
        return false;
    }
  bool canCross(vector<int>& stones) {
      // cs,pj,stones
      int n = stones.size();
      unordered_map<int, int> mp;
      for (int i = 0; i < n; i++) mp[stones[i]] = i;
      return f(0, 0, stones, mp);
  }
};






class Solution {
public:
    bool f(int cs, int pj, vector<int>& stones, unordered_map<int, int>& mp,vector<vector<int>>& dp) {
        if (cs == stones.size() - 1)return true;
        if (dp[cs][pj] != -1)return dp[cs][pj];
        int curr_pos = stones[cs];

        int next_jump = pj - 1;
        if (next_jump > 0) {
            int next_pos = curr_pos + next_jump;
            if (mp.find(next_pos) != mp.end()) {
                if (f(mp[next_pos], next_jump, stones, mp, dp))return dp[cs][pj] = true;
            }
        }
        next_jump = pj;
        if (next_jump > 0) {
            int next_pos = curr_pos + next_jump;
            if (mp.find(next_pos) != mp.end()) {
                if (f(mp[next_pos], next_jump, stones, mp, dp))return dp[cs][pj] = true;
            }
        }

        next_jump = pj + 1;
        int next_pos = curr_pos + next_jump;
        if (mp.find(next_pos) != mp.end()) {
            if (f(mp[next_pos], next_jump, stones, mp, dp))return dp[cs][pj] = true;
        }
        return dp[cs][pj] = false;
    }
  bool canCross(vector<int>& stones) {
      // cs,pj,stones
      int n = stones.size();
      unordered_map<int, int> mp;
      for (int i = 0; i < n; i++) mp[stones[i]] = i;
      vector<vector<int>> dp(n, vector<int>(n, -1));
      return f(0, 0, stones, mp, dp);
  }
};







class Solution {
public:
bool f(int cs, int pj, unordered_map<int, int>&mp, vector<int>&arr,vector<vector<int>>&dp){
    if(cs==arr.size()-1) return true;
    if(dp[cs][pj] != -1) return dp[cs][pj];
    int curr_pos=arr[cs];
        for (int next_jump = pj - 1; next_jump <= pj + 1; next_jump++) {
            if (next_jump > 0) { 
                int next_pos = curr_pos + next_jump;
                if (mp.find(next_pos) != mp.end()) { 
                    if(f(mp[next_pos],next_jump, mp, arr,dp)) return dp[cs][pj]= true;
                }
            }
        }
        return dp[cs][pj]= false;
    }
bool canCross(vector<int>& stones) {
    int n=stones.size();
    vector<vector<int>>dp(n,vector<int>(n,-1));
    unordered_map<int,int>mp;
    for (int i = 0; i < stones.size(); i++)  mp[stones[i]] = i;
    return f(0,0,mp,stones,dp);
}
}






// use hashset to remove duplicacy
class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        unordered_map<int, unordered_set<int>> mp;
        for (int stone : stones) mp[stone] = unordered_set<int>();
        mp[stones[0]].insert(0);
        for (int i = 0; i < n; ++i) {
            int currStone = stones[i];
            for (int k : mp[currStone]) {
                if (k - 1 > 0 && mp.count(currStone + k - 1)) {
                    mp[currStone + k - 1].insert(k - 1);
                }
                if (k > 0 && mp.count(currStone + k)) {
                    mp[currStone + k].insert(k);
                }
                if (mp.count(currStone + k + 1)) {
                    mp[currStone + k + 1].insert(k + 1);
                }
            }
        }
        
        return !mp[stones.back()].empty();
    }
};











class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int, unordered_set<int>> mp;
        for (int stone : stones) mp[stone] = unordered_set<int>();
        mp[stones[0]].insert(0);
        for (int stone : stones) {     
            for (int k : mp[stone]) {
                if (k-1 > 0 && mp.find(stone + k-1) != mp.end())
                    mp[stone + k-1].insert(k - 1);
                
                if (k > 0 && mp.find(stone + k) != mp.end())
                    mp[stone + k].insert(k);
                
                if (mp.find(stone + k+1) != mp.end())
                    mp[stone + k+1].insert(k + 1);       
            }
        }
      
        return !mp[stones.back()].empty();
    }
};









class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int, unordered_set<int>> mp;
        for (int stone : stones) mp[stone] = {}; 
        
        mp[stones[0]].insert(0);
        
        for (int stone : stones) {     
            for (int k : mp[stone]) {
                for (int next_jump = k - 1; next_jump <= k + 1; next_jump++) {
                    if (next_jump > 0 && mp.find(stone + next_jump) != mp.end()) {
                        mp[stone + next_jump].insert(next_jump);
                    }
                }
            }
        }
      
        return !mp[stones.back()].empty();
    }
};








