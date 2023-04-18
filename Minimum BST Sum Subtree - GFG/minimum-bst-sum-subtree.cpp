//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }

    Node *buildTree(string s) {
        if (s.length() == 0 || s[0] == 'N') return NULL;

        // Create the root of the tree
        vector<string> str;
        istringstream iss(s);
        for (string s; iss >> s;) str.push_back(s);
        Node *root = new Node(stoi(str[0]));

        // Push the root to the queue
        queue<Node*> q;
        q.push(root);

        // Starting from the second element
        int i = 1;
        while (q.size() > 0 && i < str.size()) {

            // Get and remove the front of the queue
            Node *currNode = q.front();
            q.pop();

            // Get the current node's value from the string
            string currVal = str[i];

            // If the left child is not null
            if (currVal != "N") {

                // Create the left child for the current node
                currNode->left = new Node(stoi(currVal));
                // Push it to the queue
                q.push(currNode->left);
            }

            // For the right child
            i++;
            if (i >= str.size()) break;

            currVal = str[i];

            // If the right child is not null
            if (currVal != "N") {

                // Create the right child for the current node
                currNode->right = new Node(stoi(currVal));

                // Push it to the queue
                q.push(currNode->right);
            }
            i++;
        }

        return root;
    }

    void inorder(Node *root) {
        if (root == NULL) return;
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
};


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    bool bst(Node *root,int min,int max,int&s,int&c,int&s1)
    {
        if(root==NULL)
        {
            return true;
        }
        if(root->data>=max || root->data<=min)
        {
            return false;
        }
        s+=root->data;
        c++;
        s1+=root->data;
        bool l=bst(root->left,min,root->data,s,c,s1);
        bool k=bst(root->right,root->data,max,s,c,s1);
        if(l&k)
        {
            return true;
        }
        return false;
    }
    void burrapadu(Node *root,int x,int &ans)
    {
        if(root==NULL)
        {
            return;
        }
        int s=0;
        int c=0;
        int s1=0;
        if(bst(root,INT_MIN,INT_MAX,s,c,s1))
        {
            if(s==x)
            {
                ans=min(ans,c);
            }
        }
        burrapadu(root->left,x,ans);
        burrapadu(root->right,x,ans);
    }
    int minSubtreeSumBST(int x, Node *root) {
        // code here
        int ans=9999;
        burrapadu(root,x,ans);
        if(ans==9999)
        {
            return -1;
        }
        return ans;
        
    }
};

//{ Driver Code Starts.


int main(){
    
    int t;
    cin>>t;
    while(t--){
        int target;
        cin>>target;
        string str;
        getline(cin,str);
        getline(cin,str);
        Node node(0);
        Node *root = node.buildTree(str);
        Solution ob;
        int res = ob.minSubtreeSumBST(target, root);
        cout<<res<<endl;
    }
    return 0;
}
// } Driver Code Ends