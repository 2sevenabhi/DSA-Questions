class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        // making the adjacency list
        int sz = edges.size();
        vector<pair<int,double>> adj[n];
        for(int i=0; i<sz; i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        
        // the dis/probability vector and max heap
        vector<double> dis(n,0.0);
        dis[start] = 1.0;
        priority_queue<pair<double,int>> pq;
        pq.push({1.0,start});

        // traversal
        while(!pq.empty())
        {
            auto it = pq.top();
            int node = it.second;
            double w = it.first;
            pq.pop();
            for(auto i:adj[node])
            {
                int adjNode = i.first;
                double adjW = i.second;
                if(w*adjW>dis[adjNode])
                {
                    dis[adjNode] = w*adjW;
                    pq.push({dis[adjNode],adjNode});
                }
            }
        }
        return dis[end];
    }
};