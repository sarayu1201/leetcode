class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
      unordered_map<int,int>s;
      int maxLen = 0;
      for(int num:nums){
        if(!s[num]){
            s[num] = s[num-1]+s[num+1]+1;
            s[num-s[num-1]] = s[num];
            s[num+s[num+1]] = s[num];
            maxLen = max(maxLen,s[num]);
        }
      }
      return maxLen ; 
    }
};