//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
     int longestKSubstr(string s, int k) {
    // your code here
        int c=0, ans=0, j=0;
        unordered_map<int, int> m;
        for(int i=0; i<s.size(); i++){
            m[s[i]]++;
            c++;
            while(m.size()>k){
                m[s[j]]--;
                if(m[s[j]]==0)  m.erase(s[j]);
                j++;
                c--;
            }
            ans = max(ans, c);
        }
        if(m.size()<k)  return -1;
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends