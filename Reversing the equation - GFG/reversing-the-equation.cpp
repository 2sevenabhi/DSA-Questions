//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
   string reverseEqn (string s)
        {
            //code here.
            int i {}, j {};
            int n = (int)s.length();
            while(j < n)
            {
                if(s[j] == '+' || s[j] == '*' || s[j] == '-' || s[j] == '/')
                {
                    reverse(s.begin()+i,s.begin()+j);
                    if(j != n-1)
                        i = j+1;
                }
                j++;
            }
            reverse(s.begin()+i, s.begin()+j);
            reverse(s.begin(),s.end());
            return s;
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends