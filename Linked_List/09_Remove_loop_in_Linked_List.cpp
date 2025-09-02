/*
structure of linked list node:

struct Node
{
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

*/

class Solution {
  public:
    void removeLoop(Node* head) {
        Node* slowptr=head;
        Node* fastptr=head;
        
        while(fastptr!=NULL && fastptr->next!=NULL){
            slowptr=slowptr->next;
            fastptr=fastptr->next->next;
            
            if(slowptr==fastptr){
                Node* temp;
                if(slowptr==head){
                    while(slowptr->next!=head){
                        slowptr=slowptr->next;
                    }
                    
                    slowptr->next=NULL;
                    return;
                }
                slowptr=head;
                
                while(slowptr!=fastptr){
                    slowptr=slowptr->next;
                    temp=fastptr;
                    fastptr=fastptr->next;
                }
                
                temp->next=NULL;
                return;
            }
        }
        
        
        
    }
};
