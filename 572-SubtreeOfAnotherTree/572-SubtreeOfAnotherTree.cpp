// Last updated: 01/08/2026, 22:45:24
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
    bool isSubTree(vector<int>& mainTree , vector<int>& subTree , int j){
        for(int i = 0; i < subTree.size() ; i++){
            if(mainTree[j] != subTree[i]){
                return false;
            }
            j++;
            if(j > mainTree.size()){
                return false;
            }
        }
        return true;
    }

    void dfs(TreeNode* node , vector<int>& list){
        if(node == nullptr){
            list.push_back(INT_MIN);
            return;
        }
        list.push_back(node->val);
        dfs(node->left , list);
        dfs(node->right , list);
        return;        
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        vector<int> mainTree;
        vector<int> subTree;
        dfs(root , mainTree);
        dfs(subRoot , subTree);
        // bool ans = false;
        int sizeSubTree = subTree.size();
        int j = sizeSubTree - 1;
        int i = 0;
        while(j < mainTree.size()){
            if(mainTree[i] == subTree[0]){
                bool ans = isSubTree(mainTree , subTree , i);
                if(ans == true){
                    return ans;
                }
            }
            i++;
            j++;
        }
        return false;
    }
};