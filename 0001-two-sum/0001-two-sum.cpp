class Solution {
public:
     vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        int a1=0;
        int a2=0;
        unordered_map<int,int> mp;
        for(int i=0;i <= n - 1;i++){
            int need=target - nums[i];
            auto it=mp.find(need);
            if(it != mp.end()){
                a1=i;
                a2=mp[need];
                break;
            }
            mp[nums[i]]=i;
        }
    return {a1,a2};
    
        
    }
};