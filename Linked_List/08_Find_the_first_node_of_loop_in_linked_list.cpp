// User function Template for C++

/*struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }

*/
class Solution {
  public:
    Node* findFirstNode(Node* head) {
        Node* ans;
        
        Node* slowptr=head;
        Node* fastptr=head;
        int flag=0;
        while(fastptr!=NULL && fastptr->next!=NULL){
            slowptr=slowptr->next;
            fastptr=fastptr->next->next;
            
            if(fastptr==NULL) return NULL;
            
            if(slowptr==fastptr){
                slowptr=head;
                while(slowptr!=fastptr){
                    slowptr=slowptr->next;
                    fastptr=fastptr->next;
                }
                
                return slowptr;
            }
        }
        
        return NULL;
    }
};
