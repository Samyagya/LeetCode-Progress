// Last updated: 01/08/2026, 22:46:52
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
    bool ans = true;

    void dfs(TreeNode* node , vector<int>& dfsVector){
        if(node == nullptr){
            dfsVector.push_back(INT_MIN);
            return;
        }
        dfsVector.push_back(node->val);
        dfs(node->left , dfsVector);
        dfs(node->right , dfsVector);
        return;
    }    

    void bfs(TreeNode* root , vector<int>& bfsVector){
        if(root == nullptr){
            bfsVector.push_back(INT_MIN);
            return;
        }
        queue<TreeNode*> q;
        bfsVector.push_back(root->val);

        q.push(root);
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            if(curr->left != nullptr){
                bfsVector.push_back((curr->left)->val);
                q.push(curr->left);
            }else{
                bfsVector.push_back(INT_MIN);
            }

            if(curr->right != nullptr){
                bfsVector.push_back((curr->right)->val);
                q.push(curr->right);
            }else{
                bfsVector.push_back(INT_MIN);
            }
        }
        return;
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> dfsVectorP;
        vector<int> dfsVectorQ;
        dfs(p , dfsVectorP);
        dfs(q , dfsVectorQ);
        if(dfsVectorP.size() != dfsVectorQ.size()) return false;
        for(int i = 0 ; i < dfsVectorP.size() ; i++){
            if(dfsVectorP[i] != dfsVectorQ[i]){
                return false;
            }
        }

        vector<int> bfsVectorP;
        vector<int> bfsVectorQ;
        bfs(p , bfsVectorP);
        bfs(q , bfsVectorQ);
        if(bfsVectorP.size() != bfsVectorQ.size()) return false;
        for(int i = 0 ; i < bfsVectorP.size() ; i++){
            if(bfsVectorP[i] != bfsVectorQ[i]){
                return false;
            }
        }

        return true;

    }
};