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
       Node* temp=head;
       while(temp!=nullptr){
        Node* nextnode=temp->next;
        Node* copy=new Node(temp->val);
        copy->next=nextnode;
        temp->next=copy;
        temp=nextnode;
       }

       temp=head;
       while(temp!=nullptr){
        if(temp->random){temp->next->random=temp->random->next;}
        else{temp->next->random=nullptr;}
        temp=temp->next->next;
       }
       Node* dummy=new Node(-1);
       Node* td=dummy;
       temp=head;
       while(temp!=nullptr){
        td->next=temp->next;
        td=td->next;
        temp->next=temp->next->next;
        temp=temp->next;
       }
       return dummy->next;
    }
};