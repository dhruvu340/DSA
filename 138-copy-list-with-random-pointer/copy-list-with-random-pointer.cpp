/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*,Node*>m;
        m[NULL]=NULL;
        Node* temp=head;
        while(temp!=nullptr){
            Node* newone=new Node(temp->val);
            m[temp]=newone;
            temp=temp->next;
        }
        temp=head;
       
        while(temp!=nullptr){
           
                
                m[temp]->next=m[temp->next];
                m[temp]->random=m[temp->random];
                temp=temp->next;
       
        }

        return m[head];
    }
};