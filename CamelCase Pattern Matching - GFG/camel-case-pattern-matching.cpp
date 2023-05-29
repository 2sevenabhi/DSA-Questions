//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
     vector<string> CamelCase(int N, vector<string> Dictionary, string Pattern) {
        /*
        Intution : 
        1.In each word in Dictonary accumulate the capital Letters in the word,upto length equal to 
        the length of the Pattern.
        2. If the found pattern of the current Word matches with the Given pattern then take it into vector.
        3.Sort the vector to arrange the strings in lexographical order.
        
        Time Complexity : O( N*(|S| +|S|) + M*|s|log(M*|S| );
        We are iterating over the Dictonary which takes O(N)
        For each word we are calculating its Pattern it takes O(|S|) 
        and after calculating we checking whether this pattern equal to given pattern,it takes |s| time.
        Hence totally it takes  N*(|S| +|S|) 
        
        let M be the strings in the ans,and |s| be the length of the largest string. 
        Sorting takes M*|s|log(M*|S|) 
         
        Space Complexity : O(M*|S|)
        */
        vector<string> ans;
        for(int i = 0; i<N; ++i)
        {
            string currPattern = "";
            for(auto ch : Dictionary[i])
            {   
                if(currPattern.length() >= Pattern.length()) break;
                if(int(ch) < 97) currPattern += ch;
            }
            if(currPattern == Pattern)
              ans.push_back(Dictionary[i]);
        }
        sort(ans.begin(),ans.end());
        if(ans.size() > 0) return ans;
        else 
        {
            ans.push_back("-1");
            return ans;
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> Dictionary(N);
        for (int i = 0; i < N; i++) cin >> Dictionary[i];
        string Pattern;
        cin >> Pattern;
        Solution ob;
        vector<string> ans = ob.CamelCase(N, Dictionary, Pattern);
        sort(ans.begin(), ans.end());
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends