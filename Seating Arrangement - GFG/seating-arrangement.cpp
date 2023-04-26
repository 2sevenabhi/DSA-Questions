//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
  bool is_possible_to_get_seats(int n, int m, vector<int>& seats){
        // Write your code here.
        int i=0,j=m-1,ans=0,f=0,b=0,mi=0;
        int flag=0,dd=0;
        while(seats[i]==0 && i<=j){
            i++;
            f++;
        }
        ans+=f/2;
       // cout<<ans<<" ";
        while(seats[j]==0 && i<=j){
            j--;
            b++;
        }
        
        ans+=b/2;
        //cout<<ans<<" ";
        //cout<<"a"<<i<<"b"<<j<<" ";
        for(int k=i;k<=j;k++){
            if(seats[k]==0){
                mi++;
            }
            else{
                flag=1;
                ans+=(mi-1)/2;
                mi=0;
            }
        }
        if(flag==0){
            ans=(f+1)/2;
            //cout<<ans;
            if(ans>=n){
                return true;
            }
            return false;
        }
       // cout<<ans<<" ";
        if(ans>=n){
            return true;
        }
        return false;
        
    }
};

//{ Driver Code Starts.

int main(){

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int m;
        cin >> m;
        vector<int> seats(m);
        for (int i = 0; i < m; i++) {
            cin >> seats[i];
        }
        Solution obj;
        if (obj.is_possible_to_get_seats(n, m, seats)) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
}

// } Driver Code Ends