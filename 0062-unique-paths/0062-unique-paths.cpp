class Solution {
public:
    int uniquePaths(int m, int n) {
        int DP[m][n];
        int i, j;
        for(i=0; i<m; i++)
            DP[i][0] = 1;
        for(j=0; j<n; j++)
            DP[0][j] = 1;
        for(i=1; i<m; i++)
            for(j=1; j<n; j++)
                DP[i][j] = DP[i][j-1]+DP[i-1][j];
        return DP[m-1][n-1];
    }
};