class Solution {
public:
     vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        vector<int> parent(n);
        vector<int> rank(n);
        vector<int> dist(n);
        vector<pair<int, int>> sortedEdges(edgeList.size());
        vector<pair<int, int>> sortedQueries(queries.size());
        vector<bool> result(queries.size(), false);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        // Sort edges by weight
        for (int i = 0; i < edgeList.size(); i++) {
            sortedEdges[i] = make_pair(edgeList[i][2], i);
        }
        sort(sortedEdges.begin(), sortedEdges.end());

        // Sort queries by limit
        for (int i = 0; i < queries.size(); i++) {
            sortedQueries[i] = make_pair(queries[i][2], i);
        }
        sort(sortedQueries.begin(), sortedQueries.end());

        int edgeIdx = 0;

        // Process queries in increasing order of limit
        for (auto query : sortedQueries) {
            int src = queries[query.second][0];
            int dest = queries[query.second][1];
            int limit = queries[query.second][2];

            // Remove edges with weight greater than limit
            while (edgeIdx < sortedEdges.size() && sortedEdges[edgeIdx].first < limit) {
                int edge = sortedEdges[edgeIdx].second;
                int u = edgeList[edge][0];
                int v = edgeList[edge][1];

                unionSet(u, v, parent, rank, dist);
                edgeIdx++;
            }

            // Check if there is a path between src and dest with weight less than limit
            if (findSet(src, parent) == findSet(dest, parent)) {
                result[query.second] = true;
            }
        }

        return result;
    }

private:
    int findSet(int x, vector<int>& parent) {
        if (parent[x] != x) {
            parent[x] = findSet(parent[x], parent);
        }
        return parent[x];
    }

    void unionSet(int x, int y, vector<int>& parent, vector<int>& rank, vector<int>& dist) {
        int px = findSet(x, parent);
        int py = findSet(y, parent);

        if (px != py) {
            if (rank[px] < rank[py]) {
                swap(px, py);
            }

            parent[py] = px;
            rank[px] += rank[px] == rank[py];
            dist[py] = dist[x] + dist[y];
        }
    }
};