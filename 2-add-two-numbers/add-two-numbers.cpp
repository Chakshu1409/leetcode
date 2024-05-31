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
    ListNode* reversse(ListNode* head) {
    // Set the current, previous, and next pointers to their initial values
    ListNode* current = head;
    ListNode *prev = NULL, *next = NULL;

    while (current != NULL) {
        // Store next
        next = current->next;
        // Reverse the node pointer for the current node
        current->next = prev;
        // Advance the pointer one position.
        prev = current;
        current = next;
    }
    return prev; // Make the last node (prev) as the new head of the reversed list
}

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // l1=reversse(l1);
        // l2=reversse(l2);
        int carry=0;
        ListNode* ans=new ListNode(-1);
        ListNode* temp=ans;
        while(l1 != NULL && l2 != NULL){
            ListNode* current = new ListNode((l1->val +l2->val + carry)%10);
            temp->next=current;
            temp=temp->next;
            if((l1->val +l2->val + carry)/10 == 1){
                carry=1;
            }
            else{
                carry=0;
            }
            l1=l1->next;
            l2=l2->next;
        }

        if(l1!=NULL){
            while(l1!=NULL){
                ListNode* current=new ListNode((l1->val + carry)%10);
            temp->next=current;
            temp=temp->next;
            if((l1->val + carry)/10 == 1){
                carry=1;
            }
            else{
                carry=0;
            }
            l1=l1->next;
            }
            

        }
        else{
            while(l2!=NULL){
                ListNode* current=new ListNode((l2->val + carry)%10);
            temp->next=current;
            temp=temp->next;
            if((l2->val + carry)/10 == 1){
                carry=1;
            }
            else{
                carry=0;
            }
            l2=l2->next;
            }
            

        }
        if(carry==1){
            ListNode* current= new ListNode(1);
            temp->next=current;
        }
        return ans->next;
    }
};