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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return NULL;
        int lenA=0,lenB=0;
        ListNode* tailA=headA,*tailB=headB;
        
        while(tailA->next){
            tailA=tailA->next;
            lenA++;
        }
        
        while(tailB->next){
            tailB=tailB->next;
            lenB++;
        }
        if(tailA!=tailB) return NULL;
        
        if(lenA>lenB){
            for(int i=0;i<lenA-lenB;i++)
                headA=headA->next;
        }else{
            for(int i=0;i<lenB-lenA;i++)
                headB=headB->next;
        }
        
        while(headA!=headB){
            headA=headA->next;
            headB=headB->next;
        }
        
        return headA;
    }
};
