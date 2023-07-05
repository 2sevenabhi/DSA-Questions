class Solution {
public:
    int longestSubarray(vector<int>& nums) {    
    int left = 0,right = 0;
    int count = 0,total =0,maxi = 0;
    while(right < nums.size())
    {
        if(nums[right] == 0)
        {
            count++;
            while(count > 1)
            {
                if(!nums[left])
                   --count;
                else
                   --total;
                ++left;
            }
        }
        else
        {
            ++total;
            maxi = max(maxi,total);
        }
        right++;
    }
    if(maxi == nums.size())
    {
        maxi--;
    }

    return maxi;
    }
};