//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int isPossible(int n, int m, string s){
        int u = 0, d = 0, l = 0, r = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == 'U'){
                u++;
                if(u == n) return 0;
                if(d > 0) d--;
            }
            else if(s[i] == 'D'){
                d++;
                if(d == n) return 0;
                if(u > 0) u--;
            }
            else if(s[i] == 'L'){
                l++;
                if(l == m) return 0;
                if(r > 0) r--;
            }
            else if(s[i] == 'R'){
                r++;
                if(r == m) return 0;
                if(l > 0) l--;
            }
        }
        return 1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.isPossible(n, m, s)<<endl;
    }
    return 0;
}
// } Driver Code Ends