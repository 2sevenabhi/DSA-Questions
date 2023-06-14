//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
     long long maxDiamonds(int A[], int N, int K) {
    long long ans = 0;
   make_heap(A,A+N);

   for(int i=0;i<K;i++)
   {
       pop_heap(A,A+N);
       ans+=A[N-1];
       A[N-1]/=2;
       push_heap(A,A+N);
   }
   return ans;
}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        
        cin>>N>>K;
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.maxDiamonds(A,N,K) << endl;
    }
    return 0;
}
// } Driver Code Ends