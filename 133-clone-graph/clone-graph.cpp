/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node)return nullptr;
        queue<Node*>q;
        unordered_map<Node*,Node*>m;
        q.push(node);
        Node* copy=new Node(node->val,{});
        m[node]=copy;
        while(!q.empty()){
            Node* temp=q.front();
            q.pop();
            for(auto padosi:temp->neighbors){
               
                if(m.find(padosi)==m.end()){
                    Node* t1=new Node(padosi->val,{});
                    m[padosi]=t1;
                    q.push(padosi);
                }
                m[temp]->neighbors.push_back(m[padosi]);
            }
        }


        return copy;
    }
};