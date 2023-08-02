class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> permute(vector<int>& nums) {
        f(nums, 0);
        return result;
    }
    vector<int> temp;
    bool find(vector<int>& temp, int x)
    {
        for(auto it: temp)
        {
            if(it == x)
                return true;
        }
        return false;
    }
    void f(vector<int>& nums, int k)
    {
        if(k >= nums.size())
        {
            result.push_back(temp);
            return;
        }
        for(int i = 0; i < nums.size(); i++)
        {
            if(!find(temp, nums[i]))
            {
                temp.push_back(nums[i]);
                f(nums, k+1);
                temp.pop_back();
            }
        }
    }
};