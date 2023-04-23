class Solution {
public:
    int mod = pow(10,9) + 7;
    int number(char s){
        return s-'0';
    }
    int number(string s){
        if(s.size() < 10)
            return stoi(s);
        else
            return INT_MAX;
    }
    int numberOfArrays(string s, int k) {
        int n = s.size();
        vector<int> dp(n+1, 0);
        dp[n] = 1;

        
        for (int i = n-1; i >= 0; i--) {
            if (!number(s[i])) {
                dp[i] = 0;
            } else {
                long long ans = 0;
                long long num = 0;
                for (int j = i; j < n; j++) {
                    num = num * 10 + number(s[j]);
                    if (num > k) break;
                    ans += dp[j+1];
                    ans %= mod;
                }
                dp[i] = ans;
            }
        }
        return dp[0];
    }
};