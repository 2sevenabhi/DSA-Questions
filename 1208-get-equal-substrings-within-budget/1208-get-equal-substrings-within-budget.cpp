class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
int cost=0;
        int maxlength=0;
        int j=0;
        
        for(int i=0;i<s.length();i++){
      cost+=abs(s[i]-t[i]);
            while(cost>maxCost){
                cost-=abs(s[j]-t[j]);
                j++;
            }
            maxlength=max(maxlength,i-j+1);
    }
        return maxlength;
    }
};