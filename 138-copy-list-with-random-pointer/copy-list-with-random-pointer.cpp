/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:

    Node* insertCopies(Node* head){
        Node* temp=head;

        while(temp!=NULL){
            Node* copy= new Node(temp->val);
            Node* next= temp->next;
            temp->next=copy;
            copy->next=next;
            temp=next;
        }   

        return head;
    }

    Node* RandomAdd(Node* head){
        Node* temp=head;

        while(temp!=NULL){
            if(temp->random != NULL){
                temp->next->random=temp->random->next;
            }
            temp=temp->next->next;
        }
        return head;
    }

    Node* makeFinalCopy(Node* head){
        Node* dummy=new Node(-1);
        Node* temp=head;
        Node* it=dummy;
        while(temp!=NULL){
            it->next=temp->next;
            temp->next=temp->next->next;
            temp=temp->next;
            it=it->next;
        }

        return dummy->next;
    }

    Node* copyRandomList(Node* head) {

        if(head==NULL){
            return NULL;
        }
        
        Node* inserted= insertCopies(head);

        Node* randomPut=RandomAdd(inserted);
        // return randomPut;
        Node* ans= makeFinalCopy(randomPut);

        return ans;
    }
};