/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void traverse(Node* node){
        if(node==NULL) return;
        if(node->left==NULL && node->right==NULL) return;
        
        traverse(node->left);
        traverse(node->right);
        
        Node* l=node->left;
        Node* r=node->right;
        
        if(l==NULL){
            node->left=r;
            node->right=NULL;
        }
        
        if(r==NULL){
            node->left=NULL;
            node->right=l;
        }
        
        if(l && r){
            node->left=r;
            node->right=l;
        }
        
        
    }
    
    void mirror(Node* node) {
        
        traverse(node);
        
    }
};
