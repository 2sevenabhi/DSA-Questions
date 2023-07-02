class Solution {
private:
    int res, n;
public:
    void dfs(int i, int r, vector<int>& net, vector<vector<int>>& reqs) {
        if(i == reqs.size()) {
            for(int i=0; i<n; i++) {
                if(net[i] != 0)
                    return;
            }
            res = max(res, r);
            return;
        }
        
        //accept ith request
        int from = reqs[i][0], to = reqs[i][1];
        net[from] -= 1;
        net[to] += 1;
        dfs(i+1, r+1, net, reqs);
        //do not accept ith request
        net[from] += 1;
        net[to] -= 1;
        dfs(i+1, r, net, reqs);

    }

    int maximumRequests(int n, vector<vector<int>>& reqs) {
        vector<int> net(n, 0);
        res = 0;
        this->n = n;

        dfs(0, 0, net, reqs);
        return res;
    }
};