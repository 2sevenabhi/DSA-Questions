class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int cnt=0;
        for(int i=0;i<nums.size();){
            int j=nums.size()-1;
            while(i<j){
                if(nums[i]==nums[j]){
                    cnt++;
                    j--;
                }
             else j--;
            }
            i++;
            
        }
        return cnt;
        
    }
};