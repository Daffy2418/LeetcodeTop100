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
    ListNode *merge(ListNode* head1,ListNode* head2){
        if(head1==NULL) return head2;
        if(head2==NULL) return head1;
        ListNode* dummy= new ListNode(0);
        ListNode* p=dummy;
        while(head1 && head2){
            if(head1->val<head2->val){
                p->next=head1;
                head1=head1->next;
            }else{
                p->next=head2;
                head2=head2->next;
            }
            p=p->next;
        }
        if(head1==NULL)
            p->next=head2;
        if(head2==NULL)
            p->next=head1;
        return dummy->next;
    }
    
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *slow=head,*fast=head;
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* head1=head;
        ListNode* head2=slow->next;
        slow->next=NULL;
        head1=sortList(head1);
        head2=sortList(head2);
        head=merge(head1,head2);
        return head;
    }
};
