/*
  Node is defined as
    struct node
    {
        int data;
        struct Node* next;

        Node(int x){
            data = x;
            next = NULL;
        }

    }*head;
*/

class Solution {
  public:
    Node *reverseKGroup(Node *head, int k) {
        Node *prev, *curr, *after;
        Node *newHead, *groupHead, *tail;
        
        curr=head;
        newHead=NULL;
        tail=NULL;
        
        while(curr){
            groupHead=curr;
            prev=NULL;
            int count=0;
            
            while(curr && count<k){
                after=curr->next;
                curr->next=prev;
                prev=curr;
                curr=after;
                
                count++;
            }
            
            if(newHead==NULL){
                newHead=prev;
            }
            
            if(tail){
                tail->next=prev;
            }
            
            tail=groupHead;
        }
        
        return newHead;
        
    }
};
