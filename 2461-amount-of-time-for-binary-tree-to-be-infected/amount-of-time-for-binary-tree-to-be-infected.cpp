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
    int amountOfTime(TreeNode* root, int start) {
        if(root==nullptr)return 0;
        queue<TreeNode*>q;
        TreeNode* st;
        if(root->val==start){
            st=root;
        }
        q.push(root);
        map<TreeNode*,TreeNode*>m;
        while(!q.empty()){
            TreeNode* t=q.front();
            q.pop();
            if(t->val==start){
                st=t;
            }
            if(t->left){
                m[t->left]=t;
                q.push(t->left);
            }
            if(t->right){
                m[t->right]=t;
                q.push(t->right);
            }
        }

        map<TreeNode*,bool>vis;
        queue<TreeNode*>q2;
        q2.push(st);
        vis[st]=true;
        int mini=0;
        while(!q2.empty()){
           int n=q2.size();
           bool vi=false;
           for(int i=0;i<n;i++){
             TreeNode* t=q2.front();
            q2.pop();
           
            if(m[t]&&vis[m[t]]!=true){
                vi=true;
                q2.push(m[t]);
                vis[m[t]]=true;
            }

            if(t->left&&vis[t->left]!=true){
                 vi=true;
                q2.push(t->left);
                vis[t->left]=true;
            }
            if(t->right&&vis[t->right]!=true){
                 vi=true;
                q2.push(t->right);
                vis[t->right]=true;
            }
           }

            if(vi)mini++;
        }
return mini;


    }
};