class Solution {
public:
   vector<vector<int>> combine(int n, int k) {
    if (n == 0 || k == 0) {
        return vector<vector<int>>(0);
    }
    int i = 0;
    vector<int> path(k, 0);
    vector<vector<int>> results;
    
    while (i >= 0) {
        if (i == k) {
            results.push_back(vector<int>(path));
            i--;
        }
        path[i] ++;
        while (i > 0 && path[i] <= path[i - 1] || i == 0 && path[i] <= 0) {
            path[i] ++;
        }
        if (path[i] > n - k + i + 1) {
            path[i] = 0;
            i--;
        } else {
            i++;
        }
    }
    return results;
}
};