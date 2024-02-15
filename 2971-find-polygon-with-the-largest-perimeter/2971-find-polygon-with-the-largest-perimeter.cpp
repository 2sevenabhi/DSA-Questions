class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        long long sum=0;
        long long ans=-1;
        sort(nums.begin(),nums.end());
        if(nums.size()<3) return -1;
       
        for(int i=0;i<nums.size();i++){
            if(sum>nums[i]){
                ans=sum+nums[i];
                sum=ans;
            }
            else {
                sum+=nums[i];
            }
        }
    
        return ans;
    }
};