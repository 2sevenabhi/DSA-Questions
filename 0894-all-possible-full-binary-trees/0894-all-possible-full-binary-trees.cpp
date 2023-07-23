/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int, vector<TreeNode*>> cache;
    vector<TreeNode*> allPossibleFBT(int n) {
       vector<TreeNode*> res;
        if(cache[n].size()!=0) return cache[n];
        if(n == 1){
            res.push_back(new TreeNode(0));
        }
        for(int i=0; i<n; i++){
            int l=i, r=n-i-1;
            for(TreeNode* left : allPossibleFBT(l)){
                for(TreeNode* right : allPossibleFBT(r)){
                    TreeNode* root = new TreeNode(0);
                    root->left = left;
                    root->right = right;
                    res.push_back(root);
                }
            }
        }
        cache[n] = res;
        return res;

    }
};