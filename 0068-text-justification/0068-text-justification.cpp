class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        int it = 0, i = 0;
        vector<string> ans;
        while(i < n) {
            int j = i;
            int tot = 0;
            while(j < n && tot + (tot == 0 ? 0 : 1) + (int)words[j].size() <= maxWidth) {
                tot += (tot == 0 ? 0 : 1) + (int)words[j].size();
                j++;
            }
            ans.push_back("");
            if(j == n) {
                while(i < n) {
                    ans[it] += words[i];
                    if(i != j - 1)
                    ans[it].push_back(' ');
                    i++;
                }
                int rem = maxWidth - tot;
                while(rem--) ans[it].push_back(' ');
                return ans;
            }else {
                int parts = j - i - 1;
                if(parts == 0) {
                    int rem = maxWidth - (int)words[i].size();
                    ans[it] = words[i];
                    for(int k = 0; k < rem; k++) ans[it].push_back(' ');
                }else {
                    int spaces = maxWidth - (tot - parts);
                    while(i < j) {
                        ans[it] += words[i];
                        if(i == j - 1) break;
                        int len = spaces / parts + (spaces % parts > 0);
                        if(spaces % parts) spaces--;
                        ans[it] += string(len, ' ');
                        i++;
                    }
                }
            }
            i = j;
            it++;
        }
        return {};
    }
};