class Solution {
public:
   int ans = 0;

    void dfs(int i, vector<bool>& isVis, vector<vector<int>>& adjList){
        if (isVis[i]){
            return;
        }
        isVis[i] = true;
        for (auto j : adjList[i]){
            dfs(j, isVis, adjList);
        }
    }


    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> isVis(n+1, false);
        vector<vector<int>> adjList(n+1);
        for (int i = 0; i<n; i++){
            for (int j = 0; j<n; j++){
                if (isConnected[i][j] == 1){
                    adjList[i+1].push_back(j+1);
                    adjList[j+1].push_back(i+1);
                }
            }
        }
        
        for (int i = 1; i<=n; i++){
            if (!isVis[i]){
                dfs(i, isVis, adjList);
                ++ans;
            }
        }
        return ans;
    }
};