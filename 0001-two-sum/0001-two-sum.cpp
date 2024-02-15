class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       unordered_map<int,int>mpp;
       
        // for(auto it:nums){
        //     mpp[it]++;
        // }
        for(int i=0;i<nums.size();i++){
            int remaining=target-nums[i];
            while(mpp.find(remaining)!=mpp.end()) {
               return {i,mpp[remaining]};
            }
            mpp[nums[i]]=i;
        }
        return {};
    }
};