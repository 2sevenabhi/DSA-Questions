class Solution {
    map<string,int>ma;
    vector<long long>mask;
    int n,m;
    vector<int>ans,temp;
    vector<vector<int>>dp;
    void solve(int i,long long curmax)
    {
        if(i==m)
        {
            if(curmax==(1<<n)-1)
            {
                if(ans.empty() || temp.size()<ans.size())
                    ans=temp;
            }
            return;
        }
            if(curmax==(1<<n)-1)
            {
                if(ans.empty() || temp.size()<ans.size())
                    ans=temp;
                return;    
            }
        if(dp[i][curmax]!=-1)
        {
            if(dp[i][curmax]<=temp.size())return;
        }
        solve(i+1,curmax);
        temp.push_back(i);
        solve(i+1,curmax|mask[i]);
        temp.pop_back();
        if(!temp.empty())dp[i][curmax]=temp.size();
    }

public:
    Solution()
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    }
    vector<int> smallestSufficientTeam(vector<string>& req, vector<vector<string>>& people) 
    {
        n=req.size();
        m=people.size();
        if(n==0)return {};
        for(int i=0;i<n;i++)
            ma[req[i]]=i;

        mask.resize(m);

        for(int i=0;i<m;i++)
            for(auto str:people[i])
                mask[i] |=(long long) 1 <<ma[str];
        dp.resize(m,vector<int>(1<<n,-1));
        solve(0,0);
        return ans;
    }   
};