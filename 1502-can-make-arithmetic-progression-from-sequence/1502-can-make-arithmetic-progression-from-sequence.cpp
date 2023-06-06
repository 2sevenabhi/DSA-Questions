class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>&v)
    {
        if(v.size()==2)
        return true;
        sort(v.begin(),v.end());
        int maxi=v[1]-v[0];

        for(int i=1;i<v.size()-1;i++)
        {
            if(maxi==v[i+1]-v[i])
            {
                continue;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};