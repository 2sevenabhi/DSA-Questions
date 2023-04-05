class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        
        long long rv = 0, sum = 0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];

            rv = max(rv, (long long)ceil((double)sum/(i+1)));
        }
        return rv;
    }
};