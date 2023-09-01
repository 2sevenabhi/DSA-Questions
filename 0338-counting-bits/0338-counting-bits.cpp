class Solution {
public:
    vector<int> result;
    vector<int> countBits(int num) {
        
        result.push_back(0);
        
        if(num < 1)
            return result;
            
        int i = 1,index = 0;
        while(i <= num) {
            if(!(i & i-1))
            {
                index = 0;
            }
            else
            {
                index++;
            }
            i++;
            result.push_back(result[index]+1);
        }
        return result;
    }
};