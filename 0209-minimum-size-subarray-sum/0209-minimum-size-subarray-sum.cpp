class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans=0;
        int n= nums.size();
        for(int i=1; i<n; i++) nums[i]+=nums[i-1];
        nums.push_back(0);n++;
        for(int i=n-1; i>0 ;i--) nums[i]=nums[i-1];
        nums[0]=0;

        int i=0, j=n-1, minlen=n;
        while(i<=j&& j<n){
            if(nums[j]-nums[i]>=target) {
                minlen=min(minlen,j-i);
                j--;
            }
            else j++,i++;
            
        }
        return (minlen==n? 0 : minlen);
    }
};