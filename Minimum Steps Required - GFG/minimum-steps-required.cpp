//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

int minSteps(string str) {
    int as = 0, bs = 0;
    for(int i = 0; i < str.size(); i++) {
        int j = i;
        while(j < str.size() and str[i] == str[j]) j++;
        
        if(str[i] == 'a') as++;
        else bs++;
        
        i = j - 1;
    }
    
    return min(as, bs) + 1;
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        cout << minSteps(str) << endl;
    }
}

// } Driver Code Ends