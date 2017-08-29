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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(n<1) return head;
        
        int i=0;
        ListNode *before=head;
        while(i<n+1 && before){
            before=before->next;
            i++;
        }
        
        if(i==n+1){
            ListNode *after=head;
            while(before){
                before=before->next;
                after=after->next;
            }
            
            ListNode *temp=after->next;
            after->next=temp->next;
            delete temp;
        }
        else if(i==n){
            ListNode *temp=head;
            head=head->next;
            delete temp;
        }
        
        return head;
    }
};
