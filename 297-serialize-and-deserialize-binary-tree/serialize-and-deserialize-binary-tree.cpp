/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==nullptr)return "";
        queue<TreeNode*>q;
        q.push(root);
       string s=to_string(root->val)+",";
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left){
                    q.push(temp->left);
                    s+=to_string(temp->left->val)+",";
                }else{
                    s+="#,";
                }
                if(temp->right){
                    q.push(temp->right);
                    s+=to_string(temp->right->val)+",";
                }else{
                    s+="#,";
                }
            }
        }


        return s;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0)return nullptr;
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode* root=new TreeNode(stoi(str));
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* temp=q.front();
                q.pop();
                string str1;
                getline(s,str1,',');
                if(str1!="#"){
                    TreeNode* nn=new TreeNode(stoi(str1));
                    temp->left=nn;
                    q.push(nn);

                }else{
                    temp->left=nullptr;
                }
                string str2;
                getline(s,str2,',');
                if(str2!="#"){
                    TreeNode* nn=new TreeNode(stoi(str2));
                    temp->right=nn;
                    q.push(nn);

                }else{
                    temp->right=nullptr;
                }
            }
        }


        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));