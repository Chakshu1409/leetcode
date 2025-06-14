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
    ListNode* revers(ListNode* head){
        if(head==NULL || head->next==NULL){
            return head;
        }

        ListNode* current=head;
        ListNode* prev=NULL;
        ListNode* next=NULL;

        while(current!=NULL){
            next=current->next;
            current->next=prev;
            prev=current;
            current=next;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next == NULL){
            return true;
        }

        ListNode* slow=head;
        ListNode* fast=head;

        while(fast!= NULL && fast->next!=NULL){
            slow=slow->next; 
            fast=fast->next->next;
        }
        if(fast!=NULL){
            slow=slow->next;
        }

        ListNode* HalfReversed= revers(slow);

        ListNode* temp=head;
        while(HalfReversed!=NULL){
            if(HalfReversed->val != temp->val){
                return false;
            }
            temp=temp->next;
            HalfReversed=HalfReversed->next;
        }
        return true;
    }
};