class Solution {
public:
    int maxProfit(vector<int>& prices, int f) 
    {
        ios::sync_with_stdio(0);
        cin.tie(0);
        int n=prices.size();
        int cur[2]={};
        int temp;
        for(int i=n-1;i>=0;i--)
        {
            temp=cur[0];
            cur[0]=max(cur[0],cur[1]-f+prices[i]);
            cur[1]=max(temp-prices[i],cur[1]);
        }
        return cur[1];

    }
};