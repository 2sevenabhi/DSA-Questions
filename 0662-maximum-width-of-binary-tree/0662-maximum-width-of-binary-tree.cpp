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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        long long max1=1;
        queue<pair<TreeNode*,long long>>q;
        q.push({root,0});
        while(!q.empty()){
            int size=q.size();
            long long x=-1;
            long long y=-1;
            long long k=0;
            while(size--){
                pair<TreeNode*,long long>f=q.front();
                q.pop();
                if(f.first->left!=NULL){
                    if(x==-1){
                        x=(2*f.second)+1;
                        k=x;
                        x=0;
                        y=max(y,x);
                    }
                    q.push({f.first->left,(2*f.second)+1-k});
                    y=max(y,(2*f.second)+1-k);
                }
                if(f.first->right!=NULL){
                    if(x==-1){
                        x=(2*f.second)+2;
                        k=x;
                        x=0;
                        y=max(y,x);
                    }
                    q.push({f.first->right,(2*f.second)+2-k});
                    y=max(y,(2*f.second)+2-k);
                }
            }
            if(y-x+1>max1){
                max1=y-x+1;
            }
        }
        return max1;
    }
};