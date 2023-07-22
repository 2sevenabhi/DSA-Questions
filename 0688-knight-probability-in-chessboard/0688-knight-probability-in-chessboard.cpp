class Solution {
public:
    double check(int n,int k,int row,int column,double in,vector<vector<vector<double>>>&dp){
        if(k==0){
            // all=all+1;
            if(row>=0 && row<n && column>=0 && column<n){
                in=in+1;
                cout<<row<<" "<<column<<endl;
                return 1;
            }
            return 0;
        }
        // cout<<row<<" "<<column<<endl;
        if(dp[row][column][k] != -1){
            return dp[row][column][k];
        }
        double res=0;
        if(row>=0 && row<n && column>=0 && column<n){
            // in=in+1;
            int drow[]={-2,-2,-1,+1,+2,+2,+1,-1};
            int dcol[]={-1,+1,+2,+2,+1,-1,-2,-2};
            for(int i=0;i<8;i++){
                int trow=row+drow[i];
                int tcol=column+dcol[i];
                if(trow>=0 && trow<n && tcol>=0 && tcol<n){
                    res+=check(n,k-1,trow,tcol,in,dp);
                }
            }
        }
        return dp[row][column][k]=res;
    }
    double knightProbability(int n, int k, int row, int column) {
        double in=0;
        double all=pow(8,k);
        vector<vector<vector<double>>>dp(n,vector<vector<double>>(n,vector<double>(k+1,-1)));
        in=check(n,k,row,column,0,dp);
        return in/all;
    }
};