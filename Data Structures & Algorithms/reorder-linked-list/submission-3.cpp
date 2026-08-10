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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL)return head;
        ListNode* prev=NULL;
        ListNode* next=NULL;
        ListNode* temp=head;
        while(temp)
        {
            next=temp->next;
            temp->next=prev;
            prev=temp;
            temp=next;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL)return;
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast && fast->next)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode* t1=head;
        ListNode* t2=slow->next;
        if(t2==NULL)return;
        slow->next=NULL;
        t2=reverseList(t2);
        ListNode* temp=NULL;
        while(t1 && t2)
        {
            ListNode* n1 = t1->next;
            ListNode* n2 = t2->next;

            if(temp == NULL)
            {
                temp = t1;
                temp->next = t2;
                temp = temp->next;
            }
            else
            {
                temp->next = t1;
                temp = temp->next;

                temp->next = t2;
                temp = temp->next;
            }

            t1 = n1;
            t2 = n2;
        }
        if(t1)temp->next=t1;
        else temp->next=t2;
        // head=newHead;
    }
};
