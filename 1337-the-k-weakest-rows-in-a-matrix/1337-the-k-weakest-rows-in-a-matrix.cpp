class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>>ans;
        vector<int> finalans;
        int n=mat.size(), m=mat[0].size();
        for(int i=0;i<n;i++){
            int temp=0;   //cnt
            for(int j=0;j<m;j++){
                if(mat[i][j]==1){
                   temp=temp+1;
                }  
            }
            ans.push_back({temp,i});
        }
        sort(ans.begin(),ans.end());
        for(int i=0; i<k; i++){
            finalans.push_back(ans[i].second);
        }
        return finalans;
    }
};