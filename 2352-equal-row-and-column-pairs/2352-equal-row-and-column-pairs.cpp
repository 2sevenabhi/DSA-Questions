#include <unordered_map>
#include <vector>
class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>,int> ans;
        
        for (int i=0;i<grid.size();i++){
            ans[grid[i]]++;
        }   
        int count=0;
        for (int i=0;i<grid.size();i++){
            vector <int> x;
       
            for (int j=0;j<grid.size();j++){
                x.push_back(grid[j][i]);
                 if (ans.count(x)){
                     count=count+ans[x];

                 }
                
            
            }
           

            

        }

        return count;
        
    }
};