class Solution {
public:
    int dp[16][1 << 16];  // DP array to store precalculated states
    int help(int idx, int mask, vector<int>& nums) {
        // If all elements have been picked, return 0 as there are no more elements left
        if (mask == (1 << nums.size()) - 1)
            return 0;

        // Return the precalculated state if already computed
        if (dp[idx][mask] != -1)
            return dp[idx][mask];

        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            // If the current element is not picked so far, pick it
            if (((mask >> i) & 1) == 0) {
                // Find a pair for the picked element
                for (int j = 0; j < nums.size(); j++) {
                    // Avoid picking the same element and check if it's not picked already
                    if (j != i && ((mask >> j) & 1) == 0) {
                        // Include the current pair in the answer
                        // Recur for the next state by enabling the ith and jth bits of mask
                        // Increment the operation count by multiplying with idx
                        ans = max(ans, idx * gcd(nums[i], nums[j]) + help(idx + 1, mask | (1 << i) | (1 << j), nums));
                    }
                }
            }
        }

        // Store the answer in the DP array and return it
        return dp[idx][mask] = ans;
    }

    int maxScore(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));  // Initialize the DP array with -1
        // Call the recursive function for the first operation with mask = 0 (no elements picked)
        return help(1, 0, nums);
    }
};
