/*Linked list Node structure

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/
class Compare{
    public:
    bool operator()(Node* a, Node* b){
        return a->data > b->data;
    }
};

class Solution {
  public:
    
    Node* mergeKLists(vector<Node*>& arr) {
        priority_queue<Node*, vector<Node*>, Compare> pq;
        
        for(Node* head: arr){
            if(head!=NULL){
                pq.push(head);
            }
        }
        
        Node* dummy=new Node(-1);
        Node* tail=dummy;
        
        while(!pq.empty()){
            Node* n=pq.top();
            pq.pop();
            
            tail->next=n;
            tail=n;
            
            if(n->next!=NULL){
                pq.push(n->next);
            }
            
        }
        
        return dummy->next;
        
        
    }
};
