/* Link list Node
struct Node {
    int data;
    Node *next;
    Node *random;

    Node(int x) {
        data = x;
        next = NULL;
        random = NULL;
    }
};*/

class Solution {
  public:
    Node *cloneLinkedList(Node *head) {
        map<Node*, Node*> mp;
        
        Node* temp=head;
        while(temp!=NULL){
            Node* new_node=new Node(temp->data);
            mp[temp]=new_node;
            temp=temp->next;
        }
        
        temp=head;
        while(temp!=NULL){
            mp[temp]->next=mp[temp->next];
            mp[temp]->random=mp[temp->random];
            temp=temp->next;
        }
        
        return mp[head];
        
    }
};
