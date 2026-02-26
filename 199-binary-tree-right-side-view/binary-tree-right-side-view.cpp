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
        
        queue<pair<TreeNode*,int>>q;
        map<int,int>m;
        if(!root)return {};
        q.push({root,0});
        m[0]=root->val;
        while(!q.empty()){
            int levelsize=q.size();
            for(int i=0;i<levelsize;i++){
                TreeNode* temp=q.front().first;
                int level=q.front().second;
                q.pop();
                if(temp->left){
                    q.push({temp->left,level+1});
                    m[level+1]=temp->left->val;
                }

                if(temp->right){
                    q.push({temp->right,level+1});
                    m[level+1]=temp->right->val;
                }
            }
        }

        vector<int>ans;
        for(auto i:m){
            ans.push_back(i.second);
        }

        return ans;
    }
};