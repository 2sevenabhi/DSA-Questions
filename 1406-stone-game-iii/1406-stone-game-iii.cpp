class Solution {
public:
    int dp[50001][2];
    int solve(int idx,vector<int>& stones,int flg)
    {
        if(idx>=stones.size())
        return 0;
        if(dp[idx][flg]!=-1)
        return dp[idx][flg];
        if(flg)
        {
            int ans = INT_MIN;
            int cnt = 0;
            int sum = 0;
            for(int i=idx;i<stones.size() && cnt<3;i++)
            {
                sum+=stones[i];
                ans = max(ans,sum+
                solve(i+1,stones,0));
                cnt++;
            }
            return dp[idx][flg] = ans;
        }
        else
        {
            int ans = INT_MAX;
            int cnt = 0;
            int sum = 0;
            for(int i=idx;i<stones.size() && cnt<3;i++)
            {
                sum+=stones[i];
                ans = min(ans,solve(i+1,stones,1)-sum);
                cnt++;
            }
            return dp[idx][flg] = ans;
        }
    }
    string stoneGameIII(vector<int>& stones) {
        memset(dp,-1,sizeof(dp));
        int ans = solve(0,stones,1);
        if(ans==0)
        return "Tie";
        if(ans>0)
        return "Alice";
        return "Bob";
    }
};