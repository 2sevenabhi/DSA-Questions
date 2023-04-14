class Solution {
public:
    int solve(string &s,int st,int en,vector<vector<int>>&dp){
        // base case
        if(st>en) return 0;
        if(st == en) return 1;

        // dp
        if(dp[st][en]!=-1) return dp[st][en];

        // case 1
        if(s[st] == s[en]) return dp[st][en] = 2 + solve(s,st+1,en-1,dp);


        // case 2
        else{

            // move st toward en while s[st] != s[en]
            int a = st, b = en;
            int call1 = 0;
            while(s[a] != s[en]){
                a++;
            }

            if(a == en) call1 = 1;
            else call1 = 2 + solve(s,a+1,en-1,dp);
            

            // move en toward st while s[st] != s[en]
            int call2 = 0;
            a = st, b = en;
            while(s[st] != s[b]){
                b--;
            }
            if(b == st) call2 = 1;
            else call2 = 2 + solve(s,st+1,b-1,dp);

            // st = st + 1 and en = en - 1
            int call3 = solve(s,st+1,en-1,dp);
            
            return dp[st][en] = max({call1,call2,call3});
        }
        return 0;
    }

    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(s,0,s.size()-1,dp);
    }
};