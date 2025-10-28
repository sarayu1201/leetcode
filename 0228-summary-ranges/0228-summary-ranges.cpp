class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        int n = nums.size();
        if (n == 0) return result;

        int start = nums[0]; // start of the current range

        for (int i = 1; i <= n; i++) {
            // Check if current number is not consecutive
            if (i == n || nums[i] != nums[i - 1] + 1) {
                // If start == previous number → single element
                if (start == nums[i - 1]) {
                    result.push_back(to_string(start));
                } 
                // Otherwise → range (a->b)
                else {
                    result.push_back(to_string(start) + "->" + to_string(nums[i - 1]));
                }
                // Start a new range
                if (i < n) start = nums[i];
            }
        }

        return result;
    }
};
