//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
     int maxIntersections(vector<vector<int>> lines, int N) {

 

       map<int,int> mp;

 

       for(auto it:lines){

 

           int start=it[0];

 

           int end=it[1]+1;

 

           mp[start]++;

 

           mp[end]--;

 

       }

 

       

 

       int prefix=0;

 

       int ans=1;

 

       for(auto it: mp){

 

           prefix=prefix+it.second;

 

           ans=max(ans,prefix);

 

       }

 

       return ans;

 

    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> mat(N, vector<int>(2));
        for (int j = 0; j < 2; j++) {
            for (int i = 0; i < N; i++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        cout << obj.maxIntersections(mat, N) << endl;
    }
}
// } Driver Code Ends