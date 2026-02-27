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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>>m;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        m[0][0].insert(root->val);
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* temp=q.front().first;
                int level=q.front().second.second;
                int line=q.front().second.first;
                q.pop();
                if(temp->left){
                    q.push({temp->left,{line-1,level+1}});
                    m[line-1][level+1].insert(temp->left->val);
                }

                if(temp->right){
                    q.push({temp->right,{line+1,level+1}});
                    m[line+1][level+1].insert(temp->right->val);
                }
            }
        }


        vector<vector<int>>ans;
        for(auto el:m){
            vector<int>t;
            for(auto i:el.second){
                for(auto j:i.second){
                    t.push_back(j);
                }
            }

            ans.push_back(t);
        }

        return ans;
        
    }
};