class Solution {
public:

    int dp[21][21][2];
    int acc(vector<int>& nums,int l,int r,bool playerA){
        if(l>r) return 0;
        if(dp[l][r][playerA]) return dp[l][r][playerA];
        if(playerA)
            return dp[l][r][playerA]=max(nums[l]+acc(nums,l+1,r,0),nums[r]+acc(nums,l,r-1,0));
        else
            return dp[l][r][playerA]=min(acc(nums,l+1,r,1),acc(nums,l,r-1,1));
    }
    bool PredictTheWinner(vector<int>& nums) {
        memset(dp,0,sizeof(dp));
        int p=acc(nums,0,nums.size()-1,1);
        int total=0;
        for(auto n:nums) total+=n;
        return p<total-p?0:1;
    }
};