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
 class Data{
    public:
    bool isbst;
    int minval;
    int maxval;
    int sum;
    Data(bool isbst,int minval,int maxval,int sum){
        this->isbst=isbst;
        this->minval=minval;
        this->maxval=maxval;
        this->sum=sum;
    }
 };
class Solution {
public:
    int ans=0;
    Data solve(TreeNode* root){
        if(root==nullptr)return Data(true,INT_MAX,INT_MIN,0);
        Data left=solve(root->left);
        Data right=solve(root->right);
        if(left.isbst&&right.isbst&&left.maxval<root->val&&root->val<right.minval){
            int sum=left.sum+right.sum+root->val;
            ans=max(ans,sum);
            int minval=min(root->val,left.minval);
            int maxval=max(root->val,right.maxval);
            return Data(true,minval,maxval,sum);
        }
        return Data(false,INT_MIN,INT_MAX,0);
    }
    int maxSumBST(TreeNode* root) {
        solve(root);
        return ans;
    }
};