//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    bool isFrequencyUnique(int n, int arr[])
    {
        map<int,int>mp;
        set<int>s1;
        set<int>s2;
      for(int i=0;i<n;i++){
            s1.insert(arr[i]);
        }
        
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        for(auto it=mp.begin();it!=mp.end();it++){
            s2.insert(it->second);
        }
        if(s1.size()!=s2.size()){
            return false;
        }
        else{
            return true;
        }
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        bool ans=ob.isFrequencyUnique(n,arr);
        if(ans)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
}
// } Driver Code Ends