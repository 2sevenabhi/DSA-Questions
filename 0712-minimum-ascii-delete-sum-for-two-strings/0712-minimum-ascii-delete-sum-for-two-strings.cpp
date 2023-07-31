class Solution {
public:
    int solve(int i, int j, string &s1, string &s2,int n1 , int n2, vector<vector<int>>& dp) {
        if (i>=n1 and j>=n2) return 0;

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        if (i < n1 and j<n2 and s1[i] == s2[j]) {
            return dp[i][j] = solve(i+1, j+1, s1, s2,n1, n2, dp);
        }

        int a = INT_MAX;
        int b = INT_MAX;

        if (i <n1) {
            a = s1[i] + solve(i+1, j, s1, s2,n1, n2, dp);
        }
        if (j < n2) {
            b = s2[j] + solve(i, j+1, s1, s2,n1, n2, dp);
        }

        return dp[i][j] = min(a, b);
    }

    int minimumDeleteSum(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        vector<vector<int>> dp(n1+1 , vector<int>(n2+1 , -1));
        return solve(0, 0, s1, s2,n1,n2, dp);
    }
};