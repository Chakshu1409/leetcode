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
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* rev=reverseList(head->next);

        ListNode* temp=rev;
        while(temp!=NULL && temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=head;
        head->next=NULL;
        return rev;
    }
};