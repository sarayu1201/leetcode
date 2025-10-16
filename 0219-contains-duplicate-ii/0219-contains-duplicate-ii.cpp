#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> window;

        for (int i = 0; i < nums.size(); i++) {
            // If already in set → duplicate within range
            if (window.count(nums[i])) 
                return true;

            // Add current number
            window.insert(nums[i]);

            // Maintain window size of k
            if (window.size() > k)
                window.erase(nums[i - k]);
        }
        return false;
    }
};
