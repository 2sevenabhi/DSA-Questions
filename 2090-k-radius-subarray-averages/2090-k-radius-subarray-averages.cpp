class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> ans(n, -1);
    if(k==0) return nums;
    long long sum = 0, i = 0, j = 0;
    while (j < n)
    {
        sum += nums[j];
        if ((j - i) / k == 2)
        {
            int avg = sum / (j - i + 1);
            ans[j - k] = avg;
            sum -= nums[i];
            i++;
        }
        j++;
    }
    return ans;
    }
};