class Solution {
public:
struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
 
        if (hash1 != hash2) {
            return hash1 ^ hash2;             
        }
         
        // If hash1 == hash2, their XOR is zero.
          return hash1;
    }
};
int helper(int start, int k,  multimap<int,pair<int,int>>& events, unordered_map<pair<int,int>,int,hash_pair>& dp){
    if(k==0) return 0;
    if(dp.find({start,k})!=dp.end()) return dp[{start,k}];
    int ans=0;
    auto it=events.upper_bound(start);
    for(;it!=events.end();it++){
        ans=max(ans,it->second.second+helper(it->second.first,k-1,events,dp));
    }
    return dp[{start,k}]= ans;
}
    int maxValue(vector<vector<int>>& events, int k) {
        multimap<int,pair<int,int>> mp;
        unordered_map<pair<int,int>,int,hash_pair> dp;
        for(auto x:events)
            mp.insert({x[0],{x[1],x[2]}});
        return helper(0,k,mp,dp);

    }
};