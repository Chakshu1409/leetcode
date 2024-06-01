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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* x=head;
        int count1=0;
        while(x!=NULL){
            count1++;
            x=x->next;
        }        

        ListNode* ans=new ListNode(-1);
        ListNode* current=head;
        ListNode* prev= NULL;
        ListNode* next=NULL;
        ListNode* temp=ans;

        while(current!=NULL){
            ListNode* initial=current;
            count1-=k;
            int count=k;
            while(current!=NULL && count1>=0 && count--){
                next=current->next;
                current->next=prev;
                prev=current;
                current=next;
            }

            if(count1>=0){
                temp->next=prev;
                temp=initial;
            }
            else{
                temp->next=current;
                return ans->next;
            }
            prev=NULL;
            next=NULL;
        }


        return ans->next;

    }
};