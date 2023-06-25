class Solution {
public:
    int mod=1e9+7;

    int solve(vector<int>& locations,int curr,int finish,int remFuel, vector<vector<int>> &dp){

        //base case
        if(remFuel<0){
            return 0;
        }

        if(dp[curr][remFuel]!=-1){
            return dp[curr][remFuel];
        }

        int res=curr==finish?1:0;

        for(int i=0;i<locations.size();i++){
            if(i!=curr){
                res=(res+solve(locations,i,finish,remFuel-abs(locations[curr]-locations[i]),dp))%mod;
            }
        }

        return dp[curr][remFuel]=res;

    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        
        int n=locations.size();

        vector<vector<int>> dp(n,vector<int>(fuel+1,-1));

        return solve(locations,start,finish,fuel,dp);
    }
};