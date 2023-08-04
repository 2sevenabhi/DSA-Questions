class Solution {
public:
    bool f(int i,string &s,map<string,int> &mp,string tmp,map<pair<int,string>,int> &dp,set<string> &st){
        if(i==s.length())
        {
            return mp.find(tmp)!=mp.end();
        }
        if(dp.count({i,tmp})){
            return dp[{i,tmp}];
        }
        bool flag=false;
        if(mp.find(tmp)!=mp.end()){
            flag|=f(i,s,mp,"",dp,st);
            flag|=f(i+1,s,mp,tmp+s[i],dp,st);
        }
        else{
            flag|=f(i+1,s,mp,tmp+s[i],dp,st);
        }
        return dp[{i,tmp}]=flag;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        map<string,int>mp;
        set<string>st;
        map<pair<int,string>,int>dp;
        for(auto x:wordDict){
            mp[x]++;
        }
        string tmp="";
        return f(0,s,mp,tmp,dp,st);
    }
};