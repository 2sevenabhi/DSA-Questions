//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
   vector<int> nearestSmallerTower(vector<int> arr) {
        
        int n = arr.size();
        
        stack<int> st;
        vector<int> res(n);
        res[n-1] = -1;
        st.push(n-1);
        
        for(int i = n-2; i >= 0; i--) {
            while(st.size() and arr[st.top()] >= arr[i])st.pop();
            
            if(st.size())res[i] = st.top();
            else res[i] = -1;
            st.push(i);
        }
        
        while(st.size())st.pop();
        
        st.push(0);
        
        for(int i = 1; i < n; i++) {
            while(st.size() and arr[st.top()] >= arr[i])st.pop();
            
            if(st.size()) {
                if(res[i] == -1) res[i] = st.top();
                else {
                    int dis1 = i - st.top() + 1, dis2 = res[i] - i + 1;
                    if(dis1 < dis2)res[i] = st.top();
                    else if(dis1 == dis2) {
                        if(arr[res[i]] == arr[st.top()]) {
                            res[i] = st.top();
                        }
                        else {
                            if(arr[res[i]] > arr[st.top()]) res[i] = st.top();
                        }
                    }
                }
                
            }
            st.push(i);
        }
        
        return res;
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution ob;
        vector<int> ans = ob.nearestSmallerTower(v);
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends