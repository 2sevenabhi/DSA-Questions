//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
   int maxIndexDiff(int arr[], int n) {
        /*
        
        tc => O(N)
        sp => O(N)
        // code here
        */
        vector<int>leftv(n);
        vector<int>rightv(n);
        
        int mini = arr[0];
        
        for(int i=0; i<n; i++)
        {
            mini = min(arr[i], mini);
            leftv[i] = mini;
            
        }
        
        int maxi = arr[n-1];
        
        for(int i=n-1; i>=0; i--)
        {
            maxi = max(arr[i], maxi);
            rightv[i] = maxi;
            
        }
        
        
        int ans = 0;
        
        int i =0; //left v
        int j = 0; // right v
        
        
        while(i<n&& j<n){
            
            if(leftv[i] <= rightv[j]){
                ans  = max(ans, (j-i));
                j++;
            }else{
                i++;
            }
        }
        
        return ans;
        
        
        
    }

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.maxIndexDiff(a, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends