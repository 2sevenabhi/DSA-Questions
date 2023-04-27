class Solution {
public:
    int bulbSwitch(int n) {
        int ans = 0;
        int i = 1 , j = 1;
        while(j <= n){
            ans++;
            j = (++i) * i;
        }
        return ans;
    }
};