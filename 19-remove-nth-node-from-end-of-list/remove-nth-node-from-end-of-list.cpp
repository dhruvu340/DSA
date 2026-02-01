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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dm=new ListNode(-1,head);
        ListNode* fast=dm;
        ListNode* slow=dm;
        for(int i=0;i<=n;i++){
            if(fast!=nullptr){fast=fast->next;}
        }

        while(fast!=nullptr){
            slow=slow->next;
            fast=fast->next;
        }


        slow->next=slow->next->next;
        return dm->next;

        

    }
};