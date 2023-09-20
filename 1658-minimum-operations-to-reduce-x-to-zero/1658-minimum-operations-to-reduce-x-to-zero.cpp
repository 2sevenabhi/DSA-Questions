class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        int target = totalSum - x;
        if (target < 0) return -1;
        if (target == 0) return n;
        
        int currSum = 0;
        int maxLength = -1;
        
        for (int l = 0, r = 0; r < n; r++) {
            currSum += nums[r];
            
            while (currSum > target && l <= r) {
                currSum -= nums[l];
                l++;
            }
            
            if (currSum == target) {
                maxLength = max(maxLength, r - l + 1);
            }
        }
        
        return maxLength == -1 ? -1 : n - maxLength;
    }
};