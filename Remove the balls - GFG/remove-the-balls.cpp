//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
       int finLength(int N, vector<int> color, vector<int> radius) {
        vector<int>v1;
        vector<int>v2;
        v1.push_back(color[0]);
        v2.push_back(radius[0]);
        for(int i=1;i<N;i++){
            if(color[i]==v1[v1.size()-1] && radius[i]==v2[v2.size()-1]){
                v1.pop_back();
                v2.pop_back();
            }
            else{
                v1.push_back(color[i]);
                v2.push_back(radius[i]);
            }
        }
        return v1.size();
    }
};


//{ Driver Code Starts.
int main() {

    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {

        int n;
        cin >> n;
        vector<int> color(n), radius(n);
        for (int i = 0; i < n; i++) cin >> color[i];
        for (int i = 0; i < n; i++) cin >> radius[i];
        int ans = sol.finLength(n, color, radius);
        cout << ans << "\n";
    }

    return 0;
}

// } Driver Code Ends