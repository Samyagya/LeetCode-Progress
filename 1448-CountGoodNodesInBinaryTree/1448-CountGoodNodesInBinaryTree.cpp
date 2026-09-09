// Last updated: 09/09/2026, 11:11:35
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
    void dfs(TreeNode* node , int& number , int maxNumber){
        if(node == nullptr){
            return;
        }

        if(node->val >= maxNumber){
            number++;
            maxNumber = node->val;
        }

        dfs(node->left , number , maxNumber);
        dfs(node->right , number , maxNumber);

        return;
    }

    int goodNodes(TreeNode* root) {
        int number = 0;
        int rootVal = root->val;
        dfs(root , number , rootVal);
        return number;
    }
};