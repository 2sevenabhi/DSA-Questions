class Solution {
public:
    int maxVowels(string s, int k) {
        // support variables
        int res = 0;
        char c;
        // getting the first k element in res
        for (int i = 0; i < k; i++) {
            c = s[i];
            if (c == 'e' || c == 'a' || c == 'o' || c == 'i' || c == 'u') res++;
        }
        // getting all the other possible windows
        for (int i = k, j = 0, curr = res, len = s.size(); i < len; i++, j++) {
            c = s[i];
            if (c == 'e' || c == 'a' || c == 'o' || c == 'i' || c == 'u') curr++;
            c = s[j];
            if (c == 'e' || c == 'a' || c == 'o' || c == 'i' || c == 'u') curr--;
            res = max(res, curr);
        }
        return res;
    }
};