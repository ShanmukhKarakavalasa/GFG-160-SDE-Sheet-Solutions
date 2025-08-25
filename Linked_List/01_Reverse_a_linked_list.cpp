/* Linked List Node structure:

struct Node
{
    int data;
    struct Node *next;
}

*/

class Solution {
  public:
    Node* reverseList(struct Node* head) {
        if(head==NULL) return head;
        if(head->next==NULL) return head;
        Node* prev=NULL;
        Node* curr=head;
        Node* after=head->next;
        
        while(curr!=NULL){
            curr->next=prev;
            prev=curr;
            curr=after;
            if(after!=NULL)  after=after->next;
        }
        
        return prev;
        
    }
};
