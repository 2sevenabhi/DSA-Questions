//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
      int arrayOperations(int n, vector<int> &arr) {
      int i = 0;
      int count =0;
      bool p =false;
      for(auto x:arr){
          if(x==0)p=true;
      }
      if(p){
          while(i<arr.size()){
          if(arr[i]!=0){
              while(arr[i]!=0){
                  i++;
              }
              count++;
          }
          else{
                i++;
          }
      }
      return count ; 
      }
     
     return -1;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        
        
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        Solution obj;
        int res = obj.arrayOperations(n, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends