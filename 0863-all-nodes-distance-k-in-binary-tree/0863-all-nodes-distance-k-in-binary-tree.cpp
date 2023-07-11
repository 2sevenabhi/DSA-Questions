/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> ans;  
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) 
    {
        if(!root) return {};
        findParent(root);
        dfs(target, K);
        return ans;
    }
    unordered_map<TreeNode*, TreeNode*> parent;  // to store the parent node of each node  
    void findParent(TreeNode* node)
    {
        if(!node) return;
        if(node->left)
        {
            parent[node->left] = node;
            findParent(node->left);
        }
        if(node->right)
        {
            parent[node->right] = node;
            findParent(node->right);
        }
    }
    unordered_set<TreeNode*> visited;    // to record the visited nodes
    void dfs(TreeNode* node, int K)
    {
        if(visited.find(node) != visited.end())
            return;
        visited.insert(node);
        if(K == 0)
        {
            ans.push_back(node->val);
            return;
        }
        if(node->left)
            dfs(node->left, K-1);
        if(node->right)
            dfs(node->right, K-1);
        if(parent[node])
            dfs(parent[node], K-1);
    }
};