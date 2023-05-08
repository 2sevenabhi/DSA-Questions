class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int count =0;
        int n=mat.size();
        if(n==1) return mat[0][0];

        for(int i=0;i<n;i++) count+=mat[i][i];

        int i=0;
        int j=n-1;
        while(i<n&&j>=0) count+=mat[i++][j--];

        if(n%2==1) count=count-mat[n/2][n/2];
        
        return count;
    }
};