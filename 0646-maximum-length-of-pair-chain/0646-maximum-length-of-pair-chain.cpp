class Solution {
public:
    bool static cmp(vector<int>& a, vector<int>& b){
        return a[1]<b[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),cmp);
        int i=0;
        int count=1;
        for(int j=1;j<pairs.size();j++){
            if(pairs[i][1]<pairs[j][0]){
                i=j;
                count++;
            }
        }
        return count;
    }
};