// Last updated: 01/08/2026, 22:46:49
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
    int dfs(TreeNode* node , int maxDepth){
        maxDepth = maxDepth + 1;
        int leftDepth = 0;
        int rightDepth = 0;
        if(node->left != nullptr) {
            leftDepth = dfs(node->left , leftDepth);
        }
        if(node-> right != nullptr){
            rightDepth = dfs(node->right , rightDepth);
        }
        maxDepth = maxDepth + max(leftDepth , rightDepth);
        return maxDepth;
    }

    int maxDepth(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        int maxDepth = 0;
        int ans = dfs(root , maxDepth);
        return ans;
    }
};