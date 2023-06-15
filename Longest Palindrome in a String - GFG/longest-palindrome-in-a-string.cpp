//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string longestPalin (string S) {

        string res1,res2;

        if(S.size()==1)
        

        return S;

        int n=S.size(),left=0,right=0, position=0,lengthofsubstring=1;

        for(int i=0;i<n;i++){

             left=i-1;

             right=i+1;
             

     while(left>=0 and right<n and S[left] == S[right]){
     
     

      if(lengthofsubstring<right-left+1){

        lengthofsubstring=right-left+1;

         position=left;}

        left--;

         right++;

     }

     left=i;

     right=i+1;

     while(left>=0 and right<n and S[left] == S[right]){

      if(lengthofsubstring<right-left+1){

     lengthofsubstring=right-left+1;

      position=left;
         
      }

       left--;

       right++;

    }

}

   return S.substr(position,lengthofsubstring);

    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends