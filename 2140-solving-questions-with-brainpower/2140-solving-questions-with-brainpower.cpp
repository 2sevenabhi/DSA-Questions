class Solution {
public:
vector<long long>dp;
long long solve(int i , vector<vector<int>>& questions)
{
    if(i>=questions.size())
     return 0;
    if(dp[i] != -1) return dp[i];
  
   long long ans = max(solve(i+1 , questions) ,solve(i+questions[i][1]+1, questions) + questions[i][0]);
    return dp[i] = ans;
}
long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        dp.resize(n,-1);      
        return solve(0,questions);
}
};