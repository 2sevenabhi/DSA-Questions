class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool>res;
        for(auto i:candies){
            if((i+extraCandies) >= *max_element(candies.begin(), candies.end()))
                res.push_back(true);
            else res.push_back(false);            
        }
        return res;
    }
};