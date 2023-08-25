class Solution {
public:

    int dp[101][101];
    int helper(string& s1, string& s2, string& s3, int i, int j)
    {
        if(i==s1.size() && j==s2.size())
            return 1;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        int k = i+j;
        if(i<s1.size() && s1[i] == s3[k] && j<s2.size() && s2[j] == s3[k])
        {
            return dp[i][j] = (helper(s1,s2,s3,i+1,j) | helper(s1,s2,s3,i,j+1));
        }
        if(i<s1.size() && s1[i] == s3[k])
            return dp[i][j] = helper(s1,s2,s3,i+1,j);
        if(j<s2.size() && s2[j] == s3[k])
            return dp[i][j] = helper(s1,s2,s3,i,j+1);
        
        return dp[i][j] = 0;

    }
    bool isInterleave(string s1, string s2, string s3) 
    {
        if(s1.size() + s2.size() != s3.size())
            return false;
        int i=0, j=0;
        memset(dp, -1, sizeof(dp));
        if(helper(s1, s2, s3, i, j) == 1)
            return true;
        return false;
        
    }
};