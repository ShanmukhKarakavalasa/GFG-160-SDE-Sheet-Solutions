/*
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
} */

class Solution {
  public:
    Node* rotate(Node* head, int k) {
        if(head==NULL) return head;
        if(head->next==NULL) return head;
        if(k==0) return head;
        
        Node* temp=head;
        int n=1;
        
        while(temp->next!=NULL){
            n++;
            temp=temp->next;
        }
        
        int rot=k%n;
        if(rot==0) return head;
        
        temp->next=head;
        
        temp=head;
        for(int i=1;i<rot;i++){
            temp=temp->next;
        }
        
        head=temp->next;
        temp->next=NULL;
        
        return head;
        
    }
};
