/* Link list Node
struct Node {
  int data;
  struct Node *next;

  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
class Solution {
  public:
    Node* sortedMerge(Node* head1, Node* head2) {
        vector<int> v;
        
        Node* temp1=head1;
        Node* temp2=head2;
        while(temp1!=nullptr && temp2!=nullptr){
            if(temp1->data < temp2->data){
                v.push_back(temp1->data);
                temp1=temp1->next;
            }
            else{
                v.push_back(temp2->data);
                temp2=temp2->next;
            }
        }
        
        while(temp1!=nullptr){
            v.push_back(temp1->data);
            temp1=temp1->next;
        }
        
        while(temp2!=nullptr){
            v.push_back(temp2->data);
            temp2=temp2->next;
        }
        
        Node* res=new Node(v[0]);
        Node* curr=res;
        
        for(int i=1;i<v.size();i++){
            curr->next=new Node(v[i]);
            curr=curr->next;
        }
        
        return res;
    }
};
