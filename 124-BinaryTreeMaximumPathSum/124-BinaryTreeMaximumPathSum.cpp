// Last updated: 01/08/2026, 22:46:37
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
    int ans = INT_MIN;

    int dfs(TreeNode* node){
        if(node == nullptr){
            return 0;
        }

        int leftNum = max(dfs(node->left) , 0);
        int rightNum = max(dfs(node->right) , 0);

        ans = max(ans , node->val + leftNum + rightNum);
        return node->val + max(leftNum , rightNum);
    }

    int maxPathSum(TreeNode* root) {
        int num = dfs(root);
        return max(num , ans);
    }
};