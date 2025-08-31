/*
struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
} */
class Solution {
  public:
    bool detectLoop(Node* head) {
        Node* fastptr=head;
        Node* slowptr=head;
        
        while(slowptr!=NULL){
            slowptr=slowptr->next;
            if(fastptr->next==NULL){
                return false;
            }
            else{
                fastptr=fastptr->next->next;
            }
            if(fastptr==NULL) return false;
            if(slowptr==fastptr) return true;
        }
        
        return false;
        
    }
};
