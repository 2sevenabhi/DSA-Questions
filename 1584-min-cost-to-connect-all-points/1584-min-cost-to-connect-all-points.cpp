class Solution {
public:
    void union_(int x,int y, vector<int>&parents)
    {
        parents[find(y,parents)]=find(x,parents);
    }
    int find(int x,vector<int>&parents)
    {
        if(parents[x]!=x)
        {
            return find(parents[x],parents);
        }
        return x;
    }
    int minCostConnectPoints(vector<vector<int>>& points) 
    {
        int n = points.size();
        vector<pair<int,pair<int,int>>>arr;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                arr.push_back({abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]),{i,j}});
            }
        }
        sort(arr.begin(),arr.end());
        set<int> s;
        int ans=0;
        map<pair<int,int>,int>mp;
        vector<int>parents(n,0);
        for(int i=0;i<n;i++)
        {
            parents[i]=i;
        }
        for(int i=0;i<arr.size();i++)
        {
            if(find(arr[i].second.first,parents)!=find(arr[i].second.second,parents))
            {
                ans+=arr[i].first;
                union_(arr[i].second.first, arr[i].second.second,parents);
            }   
        }
        return ans;
    }
};