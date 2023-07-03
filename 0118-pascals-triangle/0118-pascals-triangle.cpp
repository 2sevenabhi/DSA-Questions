class Solution {
public:
    vector<int> generateRow(int row){
        long long ans=1;
        vector<int>ansRow;
        ansRow.push_back(1);
        for(int col=1;col<row;col++){
            ans=ans*(row-col);
            ans=ans/(col);
            ansRow.push_back(ans);
        }
        return ansRow;
    }
    vector<vector<int>> generate(int numRows) {
        
       vector<vector<int>> pascalTriangle;
       
        for(int i=1;i<=numRows;i++){
           vector<int>row;
        row= generateRow(i);
            pascalTriangle.push_back(row);
        }
        return pascalTriangle;
    }
};