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
    Solution()
    {
        ios_base::sync_with_stdio(false); cin.tie(NULL);
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p=l1, *q=l2, *r=NULL, *new_node, *head;
        int value, carry=0;
        while(p!=NULL or q!=NULL)
        {
            if(p!=NULL and q!=NULL)
                value=(p->val)+(q->val)+carry;
            else if(p!=NULL and q==NULL)
                value=(p->val)+carry;
            else
                value=(q->val)+carry;
            new_node=new ListNode(value%10);
            if(p==l1)
            {
                head=new_node;
            }
            else
            {
                r=head;
                while(r->next!=NULL)
                {
                    r=r->next;
                }
                r->next=new_node;
            }
    
            if(value<10)
            {
                carry=0;
            }
            else
            {
                carry=1;
            }
            if(p!=NULL)
                p=p->next;
            if(q!=NULL)
                q=q->next;
        }
        if(carry)
        {
            new_node=new ListNode(1);
            r=head;
            while(r->next!=NULL)
            {
                r=r->next;
            }
            r->next=new_node;
        }
        return head;
        
    }
};