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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        int size=0;
        ListNode* temp=head;

        while(temp!=NULL){
            temp=temp->next;
            size++;
        }
        k=k%size;
        if(k==0){
            return head;
        }


        

        int count=size-k-1;

        temp=head;

        while(count--){
            temp=temp->next;
        }
        ListNode* next=temp->next;
        temp->next=NULL;

        ListNode* tempNext=next;

        while(tempNext->next!=NULL){
            tempNext=tempNext->next;
        }
        tempNext->next=head;
        return next;
    }
};