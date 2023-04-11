class Solution {
public:
    string removeStars(string s) {
        string ans;
        int j,count;
        for(int i=0;i<s.size();i++){
            if(s[i]!='*'){
                ans.push_back(s[i]);
                continue;
            }
            j=i;
            count=0;
            while(s[j]=='*'){
                count++;
                j++;
            }
            i+=count-1;
            while(count--){
                ans.pop_back();
            }
        }
        return ans;
    }
};