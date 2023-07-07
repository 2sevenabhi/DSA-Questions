class Solution {
public:
    int solve(string s,int k,char c){
        int n=s.size();
        int ans=0;
        int i=0;
        int j=0;
        int count=0;
        while(j<n){
            if(s[j]==c) j++;
            else{
                if(count<k){
                    j++;
                    count++;
                }
                else{
                    while(s[i]==c and i<j){
                        i++;
                    }
                    count--;
                    i++;
                }
            }
            ans=max(j-i,ans);
        }
        return ans;
    }
    int maxConsecutiveAnswers(string s, int k) {
        int k1=solve(s,k,'T');
        int k2=solve(s,k,'F');
        return max(k1,k2);
    }
};