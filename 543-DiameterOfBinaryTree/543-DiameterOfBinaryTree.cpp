// Last updated: 01/08/2026, 22:45:33
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
    int maxDiameter;

    int dfs(TreeNode* node){
        if(node == nullptr){
            return 0;
        }

        int leftDepth = dfs(node->left);
        int rightDepth = dfs(node->right);

        maxDiameter = max(maxDiameter , leftDepth + rightDepth);

        return 1 + max(leftDepth , rightDepth);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        maxDiameter = 0;

        dfs(root);

        return maxDiameter;
    }
};