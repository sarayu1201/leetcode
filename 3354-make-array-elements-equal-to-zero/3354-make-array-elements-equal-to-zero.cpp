class Solution {
public:
    // Helper function to simulate the process
    bool simulate(vector<int> nums, int start, int dir) {
        int n = nums.size();
        int curr = start;

        while (curr >= 0 && curr < n) {
            if (nums[curr] == 0) {
                curr += dir;  // move in current direction
            } else {
                nums[curr]--;  // decrease value
                dir = -dir;    // reverse direction
                curr += dir;   // move one step
            }
        }

        // check if all became zero
        for (int val : nums)
            if (val != 0) return false;

        return true;
    }

    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        // Try all starting positions where nums[i] == 0
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                if (simulate(nums, i, -1)) count++; // move left
                if (simulate(nums, i, 1)) count++;  // move right
            }
        }

        return count;
    }
};
