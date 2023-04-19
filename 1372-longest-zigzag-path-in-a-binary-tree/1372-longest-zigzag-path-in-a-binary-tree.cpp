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
void dfs(TreeNode *node, bool go_left, int curr_steps, int &ans)
{
    if (node == nullptr)
        return;

    ans = max(ans, curr_steps);

    if (go_left)
    {
        dfs(node->left, false, curr_steps + 1, ans);
        dfs(node->right, true, 1, ans);
    }
    else
    {
        dfs(node->left, false, 1, ans);
        dfs(node->right, true, curr_steps + 1, ans);
    }
}

int longestZigZag(TreeNode *root)
{
    int ans = 0;
    int curr_steps = 0;
    dfs(root, false, curr_steps, ans);
    dfs(root, true, curr_steps, ans);
    return ans;
}
};