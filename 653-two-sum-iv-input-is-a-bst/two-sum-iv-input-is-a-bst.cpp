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

class BSTIterator {
public:
    stack<TreeNode*>st;
    bool reverse;
    BSTIterator(TreeNode* root,bool isrev) {
        this->reverse=isrev;
        pushtill(root);
    }
    
    int next() {
        TreeNode* ans=this->st.top();
        this->st.pop();
        if(!reverse){pushtill(ans->right);}else{
            pushtill(ans->left);
        }
        return ans->val;
        
    }

    void pushtill(TreeNode* root){
        if(root==nullptr)return ;
        TreeNode* temp=root;
        if(!reverse){while(temp){
            this->st.push(temp);
            temp=temp->left;
        }}else{
            while(temp){
                this->st.push(temp);
                temp=temp->right;
            }
        }
    }
    
    bool hasNext() {
        return this->st.size()>0;
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator p1(root,false);
        BSTIterator q1(root,true);
        int p=p1.next(),q=q1.next();
        if(p+q==k&&p!=q)return true;
        while(p!=q){
            if(p+q>k){
                q=q1.next();
            }else if(p+q<k){
                p=p1.next();
            }else{
                return true;
            }
        }


        return false;
    }
};