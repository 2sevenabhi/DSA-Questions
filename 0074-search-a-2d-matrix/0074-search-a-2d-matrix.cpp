class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int col=matrix[0].size();
        int m=matrix.size();
        int row=0;
        while(row<m){
            if(target==matrix[row][col-1]){
                return true;
            }
            else if(target<matrix[row][col-1]){
                for(int i=0;i<col;i++){
                    if(matrix[row][i]==target){
                        return true;
                    }
                }
            }
            row++;
        }
        return false;

    }
};