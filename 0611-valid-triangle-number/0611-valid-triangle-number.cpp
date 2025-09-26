#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
    int triangleNumber(std::vector<int>& nums) {
        int n = nums.size();
        if (n < 3) {
            return 0;
        }

        
        std::sort(nums.begin(), nums.end());
        
        int count = 0;

        for (int k = n - 1; k >= 2; --k) {
            int target_c = nums[k];
            
            int i = 0;      
            int j = k - 1;  
            
            
            while (i < j) {
                
                if (nums[i] + nums[j] > target_c) {
                    
                    
                    count += (j - i);
                    
                    j--;
                } else {
                    
                    i++;
                }
            }
        }
        
        return count;
    }
};