class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        int dp[n][n];
        memset(dp, 0, sizeof dp);
        for(int i = 0; i < n ; i++)
            dp[i][i] = 1;
        int ans = 1;
        for(int l = 2; l <= n; l++)
        {
            for(int i = 0; i < n - l + 1; i++)
            {
                int j = i + l - 1;
                if(s[i] == s[j])
                {
                    if(l == 2)dp[i][j] = 2;
                    else
                        dp[i][j] = max(dp[i][j], dp[i+1][j-1] + 2);
                }
                else
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                ans = max(ans, dp[i][j]);    
            }
        }
        //cout<<ans<<"\n";
        return n - ans;
    }
};