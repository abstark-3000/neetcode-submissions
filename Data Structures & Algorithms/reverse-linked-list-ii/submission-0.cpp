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
        //Three pointer approach
        if(head==NULL)return head;
        ListNode* curr=head;
        ListNode* Next=NULL;
        ListNode* prev=NULL;
        while(curr!=NULL)
        {
            Next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=Next;
        }
        return prev;
        
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL || head->next==NULL)return head;
        ListNode* revh=head;
        ListNode* prev=NULL;
        ListNode* next=NULL;
        int i=1;
        while(revh && i<left)
        {
            prev=revh;
            revh=revh->next;
            i++;
        }
        if(prev)prev->next=NULL;
        ListNode* temp=revh;
        while(left<right && temp)
        {
            temp=temp->next;
            left++;
        }
        if(temp)next=temp->next;
        temp->next=NULL;
        revh=reverseList(revh);
        if(prev)
        {
            prev->next=revh;
            temp=revh;
            while(temp->next)temp=temp->next;
            temp->next=next;
            return head;
        }
        
        temp=revh;
        while(temp->next)temp=temp->next;
        temp->next=next;
        return revh;            
        
        
        


        
        
    }
};