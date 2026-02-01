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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* t1=l1;
        ListNode* t2=l2;
        ListNode* dm=new ListNode(-1);
        ListNode* tt=dm;
        int carry=0;
        while(t1!=nullptr||t2!=nullptr){
            int sum=0;
            if(t1){
                sum+=t1->val;
                t1=t1->next;
            }
            if(t2){
                sum+=t2->val;
                t2=t2->next;
            }
            sum+=carry;
            carry=sum/10;
            sum%=10;
            ListNode* sumofnode=new ListNode(sum);
            tt->next=sumofnode;
            tt=tt->next;

        }

        if(carry){
            ListNode* sumofnode=new ListNode(carry);
            tt->next=sumofnode;
            tt=tt->next;
        }

        return dm->next;

    }
};