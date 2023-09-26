class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int>visit(26,0);
        unordered_map<char,int>mpp;

        for(auto ch:s){
            mpp[ch]++;
        }

        string ans="";

        for(int i=0;i<s.size();i++)
        {

        mpp[s[i]]--;

        if(visit[s[i]-'a'])  continue;

        else{
            while(!ans.empty() &&  mpp[ans.back()] && ans.back() > s[i] )
            {
                visit[ans.back() -'a']=0;
                ans.pop_back();
            }

            ans.push_back(s[i]);
            visit[s[i]-'a']=1;
        }

        }

        return ans;
    }
};