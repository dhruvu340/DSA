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
        if(node == nullptr)return nullptr;
        map<Node*,Node*>m;
        Node* newNode = new Node(node->val,{});
        m[node] = newNode;
        queue<Node*>q;
        q.push(node);
        
        
        while(!q.empty()){
            int size = q.size();
            while(size--){
                Node* front = q.front();
                q.pop();
                for(auto neig : front->neighbors){
                   if(m.find(neig)==m.end()){
                    
                    q.push(neig);
                    Node* newNode = new Node(neig->val,{});
                    m[neig] = newNode;
                   }
                    m[front]->neighbors.push_back(m[neig]);  
                }
            }
        }

        return m[node];
    }
};