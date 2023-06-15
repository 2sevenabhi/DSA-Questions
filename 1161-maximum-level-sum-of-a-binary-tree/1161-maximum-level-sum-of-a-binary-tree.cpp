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

    int maxLevelSum(TreeNode* root) {
        int maxSum = -1000050, ansLevel=1, count=1,childCount=0,sumCurr=0,currLevel=1;
        queue<TreeNode*> nodes;
        nodes.push(root);
        while(!nodes.empty()){
            TreeNode* curr = nodes.front();
            sumCurr+= curr->val;
            nodes.pop();
            count--;
            if(NULL != curr->left){
                nodes.push(curr->left);
                childCount++;
            }
            if(NULL != curr->right){
                nodes.push(curr->right);
                childCount++;
            }
            if(0 == count){
                if(maxSum < sumCurr){
                    maxSum = sumCurr;
                    ansLevel = currLevel;
                }
                count = childCount;
                childCount = 0;
                sumCurr = 0;
                currLevel++;
            }
            // cout<<sumCurr;
        }

        return ansLevel;
    }
};