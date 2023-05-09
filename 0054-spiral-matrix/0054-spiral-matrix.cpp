class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};
        int l = 0, u = 0, d = matrix.size()-1, r = matrix[0].size()-1;
        vector<int> res;
        while (true) {
            for (int col = l; col <= r; ++col) res.push_back(matrix[u][col]);
            if(++u > d) break;
            for (int row = u; row <= d; ++row) res.push_back(matrix[row][r]);
            if(--r < l) break;
            for (int col = r; col >= l; --col) res.push_back(matrix[d][col]);
            if(--d < u) break;
            for (int row = d; row >= u; --row) res.push_back(matrix[row][l]);
            if(++l > r) break;
        }
        return res;
    }
};