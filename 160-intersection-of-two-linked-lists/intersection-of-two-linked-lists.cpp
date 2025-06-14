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
        ListNode* tempA=headA;
        ListNode* tempB=headB;

        while(tempA!=NULL && tempB!=NULL){
            tempA=tempA->next;
            tempB=tempB->next;
        }

        ListNode* pointer1=NULL;
        ListNode* pointer2=NULL;

        if(tempA==NULL){
            ListNode* tempTempB=headB;
            while(tempB!=NULL){
                tempB=tempB->next;
                tempTempB=tempTempB->next;
            }
            pointer1=headA;
            pointer2=tempTempB;
        }
        else{
            ListNode* tempTempA=headA;
            while(tempA!=NULL){
                tempA=tempA->next;
                tempTempA=tempTempA->next;
            }
            pointer1=tempTempA;
            pointer2=headB;
        }

        while(pointer1 != pointer2){
            pointer1=pointer1->next;
            pointer2=pointer2->next;
        }
        return pointer1;
    }
};