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

            int el=pre[ipre--];
            TreeNode* temp=new TreeNode(el);
            int idx=m[el];
            temp->right=solve(in,pre,ipre,idx+1,endin);
            temp->left=solve(in,pre,ipre,stin,idx-1);
            
            return temp;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        for(int i=0;i<n;i++){
            m[inorder[i]]=i;
        }
        int ist=n-1;
        
        return solve(inorder,postorder,ist,0,n-1);
    }
};