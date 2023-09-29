class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        vector<int>v;
        v=nums;
        sort(v.begin(),v.end());
        if(v==nums) return true;
        reverse(v.begin(),v.end());
        if(v==nums) return true;
         return false;
    }
};