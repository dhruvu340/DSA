/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* findk(ListNode* temp,int k){
        k--;
        while(temp!=nullptr&&k>0){
            k--;
           temp = temp->next;
        }

        return temp;
    }
    ListNode* reverse(ListNode* head){
        if(head==nullptr||head->next==nullptr){
            return head;
        }
        ListNode* newhead=reverse(head->next);
        ListNode* first=head->next;
        head->next=nullptr;
        first->next=head;
        return newhead;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* prev=NULL;
        while(temp!=nullptr){
            ListNode* kthnode=findk(temp,k);
            if(kthnode==NULL){
                if(prev)prev->next=temp;
                break;
            }
            ListNode* next=kthnode->next;
            kthnode->next=nullptr;
            reverse(temp);
            if(temp==head){
                head=kthnode;
            }else{
                if(prev)prev->next=kthnode;
            }
            prev=temp;
            temp=next;
        }

        return head;
    }
};