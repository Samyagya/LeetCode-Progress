// Last updated: 01/08/2026, 22:46:10
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
    vector<int> rightSideView(TreeNode* root) {
        vector<vector<int>> tree;
        vector<int> ans;
        if(root == nullptr){
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int levelSize = q.size();
            vector<int>currLevel;
            for(int i = 0 ; i < levelSize ; i++){
                TreeNode* curr = q.front();
                q.pop();
                
                currLevel.push_back(curr->val);

                if(curr->left != nullptr){
                    q.push(curr->left);
                }
                if(curr->right != nullptr){
                    q.push(curr->right);
                }
            }
            tree.push_back(currLevel);
        }
        for(int i = 0 ; i < tree.size() ; i++){
            vector<int> currLevel = tree[i];
            ans.push_back(currLevel[currLevel.size() - 1]);
        }

        return ans;
        
    }
};