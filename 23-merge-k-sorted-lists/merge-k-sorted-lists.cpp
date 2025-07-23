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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy=new ListNode(-1);
        ListNode* head=dummy;
        int size=lists.size();
        while(1){
            ListNode* maxi;
            int mini=INT_MAX;
            bool flag=false;
            for(int i=0; i<size; i++){
                if(lists[i]!=NULL){
                    if(lists[i]->val < mini){
                        mini=lists[i]->val;
                    }
                    flag=true;
                }
            }
            cout<<mini<<endl;
            if(!flag){
                break;
            }
            for(int i=0; i<size; i++){
                if(lists[i]!=NULL){
                    if(lists[i]->val == mini){
                        head->next=lists[i];
                        head=head->next;
                        lists[i]=lists[i]->next;
                        break;
                    }
                }
            }
        }
        return dummy->next;
    }
};