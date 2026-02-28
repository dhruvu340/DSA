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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==nullptr)return {};
        queue<TreeNode*>q;
        q.push(root);
        vector<vector<int>>ans;
        bool rev=true;
        ans.push_back({root->val});
        while(!q.empty()){
            int n=q.size();
            vector<int>t;
            for(int i=0;i<n;i++){
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left){
                    q.push(temp->left);
                    t.push_back(temp->left->val);

                }
                if(temp->right){
                    q.push(temp->right);
                    t.push_back(temp->right->val);
                }
            }

            if(rev){
                reverse(t.begin(),t.end());
                
                
            }
            if(t.size()!=0){ans.push_back(t);}

            rev=!rev;
        }
        return ans;
    }
};