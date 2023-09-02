class Solution {
public:
    int n;
    unordered_set<string> st;
    int t[51];
    int solve(int idx,string &s){
        if(idx>=n){
            return 0;
        }
        string curr="";
        int mini=n;
        if(t[idx]!=-1){
            return t[idx];
        }
        for(int i=idx;i<n;i++){
            curr.push_back(s[i]);
            int currextra=(st.find(curr)==st.end()) ? curr.length(): 0;
            int nextextra=solve(i+1,s);
            int total=currextra+nextextra;
            mini=min(mini,total);
        }
        return t[idx] = mini;

    }
    int minExtraChar(string s, vector<string>& dictionary) {
        n=s.length();
        memset(t,-1,sizeof(t));
        for(auto ch:dictionary){
            st.insert(ch);
        }
        return solve(0,s);
    }
};