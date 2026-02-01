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
        if(head==nullptr||head->next==nullptr)return head;
        ListNode* nh=revll(head->next);
        ListNode* first=head->next;
        head->next=nullptr;
        first->next=head;
        return nh;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast->next!=nullptr&&fast->next->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
       ListNode* sec= revll(slow->next);
       ListNode* t1=head;
       ListNode* t2=sec;
       while(t2!=nullptr){
        if(t1->val!=t2->val){
            revll(slow->next);
            return false;
        }
        t1=t1->next;
        t2=t2->next;
       }

       revll(slow->next);
       return true;
    }
};