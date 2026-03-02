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
    int countNodes(TreeNode* root) {
        if(root==nullptr)return 0;
        int ct=0;
        queue<TreeNode*>q;
        q.push(root);
        ct++;
        while(!q.empty()){
            TreeNode* t=q.front();
            q.pop();
            if(t->left){
                ct++;
                q.push(t->left);
            }

            if(t->right){
                ct++;
                q.push(t->right);

            }
        }


        return ct;
    }
};