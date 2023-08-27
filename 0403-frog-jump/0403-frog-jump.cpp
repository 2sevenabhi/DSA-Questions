#include <iostream>
#include <vector>
#include <unordered_set>

class Solution {
public:
    bool canCross(std::vector<int>& stones) {
        int n = stones.size();
        
        // Create a set for each stone to store possible jump lengths
        std::unordered_set<int> stoneSet;
        for (int stone : stones) {
            stoneSet.insert(stone);
        }
        
        // Create a dp array where dp[i][k] indicates if frog can jump to stone i with jump length k
        std::vector<std::vector<bool>> dp(n, std::vector<bool>(n + 1, false));
        dp[0][1] = true;
        
        for (int i = 1; i < n; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                int diff = stones[i] - stones[j];
                if (diff > n || !dp[j][diff]) {
                    continue;
                }
                dp[i][diff] = true;
                if (diff - 1 > 0) dp[i][diff - 1] = true;
                if (diff + 1 <= n) dp[i][diff + 1] = true;
                if (i == n - 1) return true; // Last stone reached
            }
        }
        
        return false;
    }
};