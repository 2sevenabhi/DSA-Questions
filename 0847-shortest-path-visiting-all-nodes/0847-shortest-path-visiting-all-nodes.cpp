class Solution {
    using int3 = tuple<int, int, int>;
    using int2 = pair<int, int>;
public: // bfs
    int shortestPathLength(vector<vector<int>>& graph) {
        int sz = graph.size();
        int mask = (1 << sz) - 1;
        queue<int3> bfs_q; 
        set<int2> path;

        for(int i = 0; i < sz; i++) {
            int maski = 1 << i;
            bfs_q.push({0, i, maski});
            path.insert({i, maski});
        }

        while(!bfs_q.empty()) {
            auto [d, i, maski] = bfs_q.front(); bfs_q.pop();

            if(maski == mask) return d;

            for(int j : graph[i]) {
                int maskj = maski | (1 << j);
                int2 move = {j, maskj};
                if(!path.count(move)) {
                    path.insert(move);
                    bfs_q.push({d + 1, j, maskj});
                }
            }
        }
        
        return -1;
    }
};