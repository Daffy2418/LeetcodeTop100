/*
1.找到原链表中第m-1个节点
2.反转
3.将链表反转前后的结点接回
*/
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m<1 || m>=n || !head) return head;
        ListNode *dummy=new ListNode(-1);
        dummy->next=head;
        head=dummy;
        
        for(int i=1;i<m;i++) head=head->next;
        ListNode *pre=head->next,*cur=pre->next;
        
        for(int i=m;i<n;i++){
            ListNode *temp=cur->next;
            cur->next=pre;
            pre=cur;
            cur=temp;
        }
        
        head->next->next=cur;
        head->next=pre;
        head=dummy->next;
        delete dummy;
        return head;
        }
};
