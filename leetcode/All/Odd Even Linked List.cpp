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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL or head->next==NULL) return head;
        ListNode *oddptr=head, *evenptr=(head->next), *evenhead=(head->next);
        while(oddptr->next!=NULL and evenptr->next!=NULL)
        {
            oddptr->next=evenptr->next;
            oddptr=oddptr->next;
            if(oddptr->next!=NULL)
            {
                evenptr->next=oddptr->next;
                evenptr=evenptr->next;
            }
        }
        evenptr->next=NULL;
        oddptr->next=evenhead;
        return head;
    }
};