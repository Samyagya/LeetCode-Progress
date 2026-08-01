// Last updated: 01/08/2026, 22:46:50
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> ans;
        vector<int> bfs;
        if(root == NULL){
            return ans;
        }

        bfs.push_back(root->val);
        

        while(!q.empty()){
            TreeNode* curr = q.front();
            int levelSize = q.size();
            vector<int> level;
            
            for(int i = 0 ; i < levelSize ; i++){
                TreeNode* curr = q.front();
                q.pop();

                level.push_back(curr->val);
                if(curr->left != nullptr){
                    q.push(curr->left);
                }
                if(curr->right != nullptr){
                    q.push(curr->right);
                }
            }
            ans.push_back(level);
        }

        return ans;

        

      

        return ans;
    }
};