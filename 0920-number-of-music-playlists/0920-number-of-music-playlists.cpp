class Solution {
    int mod=1e9+7;
public:

    int create_playlist(int n,int goal,int k,vector<int> &curr, unordered_map<int,int> &h_map,vector<vector<int>> &memo)
    {
        if(curr.size()==goal && h_map.size()>=n)
        {             
            return 1;
        }
        if(curr.size()==goal && h_map.size()<n)
            return 0;

        if(memo[curr.size()][h_map.size()]!=-1)
            return memo[curr.size()][h_map.size()];

        int ans=0;
        for(int i=1;i<=n;i++)
        {
            auto ptr=h_map.find(i);
            if(ptr!=h_map.end() && curr.size()-ptr->second-1<k)
                continue;

            int prev=-1;
            
            if(ptr==h_map.end())
                h_map.insert({i,curr.size()});
            else
            {   
                prev=ptr->second;
                ptr->second=curr.size();
            }

            curr.push_back(i);
            ans= (ans+create_playlist(n,goal,k,curr,h_map,memo))%mod;
            
            
            curr.pop_back();
            if(prev==-1)
                h_map.erase(i);
            else
                ptr->second=prev;
            
        }

        memo[curr.size()][h_map.size()]=ans;
        return ans;
    }


    int numMusicPlaylists(int n, int goal, int k) {
        unordered_map<int,int> h_map;
        vector<int> curr;

        vector<vector<int>> memo(goal+1,vector<int>(n+1,-1));
        return create_playlist(n,goal,k,curr,h_map,memo);
    }
};