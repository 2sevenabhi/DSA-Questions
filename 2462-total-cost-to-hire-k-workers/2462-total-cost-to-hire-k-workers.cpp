class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int c) {
        priority_queue<int,vector<int>,greater<int>> left,right;
        long long ans=0;
        int n=costs.size()-1,i=0,ctr=0;
        while(ctr<k)
        {
            while(left.size()<c&&i<=n)
            left.push(costs[i++]);
            while(right.size()<c&&n>=i)
            right.push(costs[n--]);
            int l=left.size()>0?left.top():INT_MAX;
            int r=right.size()>0?right.top():INT_MAX;
            if(l>r)
            {
                ans+=r;
                right.pop();
            }
            else
            {
                ans+=l;
                left.pop();
            }
            ctr++;
        }
        return ans;
    }
};
