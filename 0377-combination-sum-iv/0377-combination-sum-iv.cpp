class Solution {
public:
    vector<int> v;
    vector<int> dp;

    int f(int t){
        if(t==0) return 1;

        if(dp[t]!=-1) return dp[t];

        int res = 0;

        for(int i=0;i<v.size();i++){
            if(v[i]<=t)
            res+=f(t-v[i]);
        }

        return dp[t]=res;
    }

    int combinationSum4(vector<int>& nums, int target) {
        v=nums;
        dp= vector<int>(target+1,-1);
        return f(target);
    }
};