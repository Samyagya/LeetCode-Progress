// Last updated: 01/08/2026, 22:45:54
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* curr = root;
        int Pval = p->val;
        int Qval = q->val;
        while(curr != NULL){
            int currVal = curr->val;
            if(currVal > Pval && currVal > Qval){
                curr = curr->left;
            }else if(currVal < Pval && currVal < Qval){
                curr = curr->right;
            }else{
                return curr;
            }
        }
        return NULL;
    }
};