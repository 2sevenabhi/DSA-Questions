class Solution {

    vector<int>* rods;
    vector<vector<int>> dp;
    int total;

    int DFS(int index, int sum)
    {
        if(index >= rods->size())
            return sum == 0 ? 0 : INT_MIN;

        if(dp[index][sum + total] != -1)
            return dp[index][sum + total];

        int s1 = rods->at(index) + DFS(index + 1, sum + rods->at(index));
        int s2 = DFS(index + 1, sum - rods->at(index));
        int s3 = DFS(index + 1, sum);

        return dp[index][sum + total] = max(s3, max(s1, s2));
    }

public:
    int tallestBillboard(vector<int>& rods) {
        
        this->rods = &rods;
        total = accumulate(rods.begin(), rods.end(), 0);
        dp = vector<vector<int>>(rods.size(), vector<int>(2 * total + 1, -1));

        int ret = DFS(0, 0);
        
        return ret > 0 ? ret : 0;
    }
};