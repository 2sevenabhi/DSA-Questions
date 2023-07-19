class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int count=0;
        vector<pair<int,int>>v;
        for(auto c:intervals)
        {
            v.push_back({c[1],c[0]});
        }
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++)
        {
            swap(v[i].first,v[i].second);
        }
        int prev=v[0].second;
        for(int i=1;i<v.size();i++)
        {
            if(v[i].first<prev)
            {
                count++;
            }
            else
            {
                prev=v[i].second;
            }
        }
        return count;
    }
};