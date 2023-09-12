class Solution {
public:
    int minDeletions(string s) {
        int ans = 0, last = 0;

        unordered_map<int, int> m;
        for(auto i : s)    m[i]++;

        vector<int> freq;
        for(auto [_, f] : m)    freq.push_back(f);
        sort(freq.begin(), freq.end());

        stack<int> st;
        for(int i=0; i<freq.size(); i++){
            int curr = freq[i];
            for(int j=last+1; j<curr; j++)    st.push(j);
            
            if(i+1 < freq.size() && curr == freq[i+1]){
                if(!st.empty()){
                    ans += curr - st.top();
                    st.pop();
                }
                else    ans += curr;
            }
            
            last = curr;
        }

        return ans;
    }
};