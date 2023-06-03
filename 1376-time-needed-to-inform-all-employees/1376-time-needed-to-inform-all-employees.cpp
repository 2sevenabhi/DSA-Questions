class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int ans=0;
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            if(manager[i]!=-1)
                adj[manager[i]].push_back(i);
        }

        queue<pair<int,int>>q;
        q.push({headID,0});

        while(!q.empty()){
            auto p=q.front();
            q.pop();

            int node=p.first;
            int time=p.second;
            ans=max(ans,time);
            for(int i:adj[node]){
                q.push({i,time+informTime[node]});
            }
        }
        return ans;
    }
};