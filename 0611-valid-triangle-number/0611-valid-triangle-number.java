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

        // 1. Sort the array to efficiently check the triangle inequality.
        // O(N log N)
        std::sort(nums.begin(), nums.end());
        
        int count = 0;

        // 2. Iterate and Fix the Longest Side (c) at index k.
        // We iterate k from the largest possible index (n-1) down to 2.
        for (int k = n - 1; k >= 2; --k) {
            
            // The value of the longest side 'c' is nums[k].
            int target_c = nums[k];
            
            // 3. Two Pointers for sides a (i) and b (j).
            int i = 0;      // Left pointer (side a)
            int j = k - 1;  // Right pointer (side b)
            
            // This inner loop is O(N) because i moves right and j moves left.
            while (i < j) {
                // Check Triangle Inequality: a + b > c
                if (nums[i] + nums[j] > target_c) {
                    
                    // Since nums is sorted, this means nums[i] forms a valid triangle 
                    // with nums[j] and nums[k].
                    
                    // Crucially, every element between i and j (i+1, i+2, ..., j-1)
                    // will also form a valid triangle with nums[j] and nums[k], 
                    // because those elements are all >= nums[i].
                    
                    // Number of valid pairs found for the current nums[j] is (j - i).
                    count += (j - i);
                    
                    // Move the right pointer inwards (j--) to look for smaller 'b' values 
                    // that still satisfy the inequality.
                    j--;
                } else {
                    // Sum is too small (a + b <= c). 
                    // We must increase the smaller side 'a'.
                    i++;
                }
            }
        }
        
        return count;
    }
};