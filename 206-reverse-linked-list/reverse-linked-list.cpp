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
    ListNode* revll(ListNode* head){
        if(head==nullptr||head->next==nullptr){
            return head;
        }
        ListNode* newhead=revll(head->next);
        ListNode* nextn=head->next;
        nextn->next=head;
        head->next=nullptr;
        return newhead;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* prev=nullptr;
        ListNode* curr=head;
       return revll(head);
    }
};