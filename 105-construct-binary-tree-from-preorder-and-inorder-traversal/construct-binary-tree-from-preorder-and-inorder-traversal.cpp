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
    map<int,int>m;
    TreeNode* solve(vector<int>& in, vector<int>& pre , int &ipre ,int stin, int endin){
            if(ipre>=pre.size()||stin>endin)return NULL;

            int el=pre[ipre++];
            TreeNode* temp=new TreeNode(el);
            int idx=m[el];
            temp->left=solve(in,pre,ipre,stin,idx-1);
            temp->right=solve(in,pre,ipre,idx+1,endin);
            return temp;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=inorder.size();
        for(int i=0;i<n;i++){
            m[inorder[i]]=i;
        }
        int preOrderIndex=0;
        TreeNode* ans= solve ( inorder , preorder , preOrderIndex , 0 ,n-1);
        return ans;
    }
};