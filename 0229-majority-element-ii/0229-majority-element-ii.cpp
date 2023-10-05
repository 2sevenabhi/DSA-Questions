class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>ans;
        if(nums.size() == 1){
            return nums;
        }
        if(nums.size() == 2){
            if(nums[0] == nums[1]){
                ans.push_back(nums[0]);
                return ans;
            }else{
                return nums;
            }
        }
        int req=(nums.size())/3;
        unordered_map<int,int>mpp;
        for(int i =0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        for(auto it:mpp){
            if(it.second>req){
                ans.push_back(it.first);
            }
        }
       
        return ans;
    }
};