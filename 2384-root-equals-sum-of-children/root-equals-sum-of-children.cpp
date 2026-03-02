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
    bool solve(TreeNode* root){
        if(root==nullptr)return true;
        if(root->left==nullptr&&root->right==nullptr)return true;

        if(root->val==root->left->val+root->right->val){

            return solve(root->left)&&solve(root->right);
        }



        return false;
        
    }
    bool checkTree(TreeNode* root) {
        return solve(root);

    }
};