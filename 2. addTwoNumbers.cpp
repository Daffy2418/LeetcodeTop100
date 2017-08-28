/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //create a dummy node
        ListNode *dummy=new ListNode(0), *p=dummy;
        int flag=0;
        while(l1 || l2 || flag){
            if(l1){
                flag+=l1->val;
                l1=l1->next;
            }
            if(l2){
                flag+=l2->val;
                l2=l2->next;
            }
            p->next=new ListNode(flag%10);
            flag=flag/10;
            p=p->next;
        }
        return dummy->next;
    }
};
