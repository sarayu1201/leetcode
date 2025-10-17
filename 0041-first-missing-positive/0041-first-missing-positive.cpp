class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> s;
        for(int i : nums){
            if(i>0){
                s.emplace(i);
            }
        }
        for(int j =1 ;j<=nums.size()+1;j++){
            if(s.count(j)==0){
                return j;
            }
        }
        return 0;
    }
};