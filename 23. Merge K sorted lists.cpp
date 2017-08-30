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
    struct compNode{
        bool operator()(ListNode *p,ListNode *q) const{
            return p->val>q->val;
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        if(n==0) return NULL;

        priority_queue<ListNode*,vector<ListNode *>,compNode> pq;
        ListNode *dummy=new ListNode(0),*tail=dummy;
        for(int i=0;i<n;i++)
        {
            if(lists[i])
                pq.push(lists[i]);
        }
        while(!pq.empty())
        {
            tail->next=pq.top();
            tail=tail->next;
            pq.pop();
            if(tail->next) pq.push(tail->next);/*push the next listNode*/
        }
        return dummy->next;
    }
};
