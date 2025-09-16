/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    bool isLeaf(Node* root){
        if(root->left==NULL && root->right==NULL){
            return true;
        }
        
        return false;
    }
    
    void leftboundary(Node* root, vector<int>& res){
        if(root==NULL || isLeaf(root)){
            return;
        }
        
        res.push_back(root->data);
        
        if(root->left){
            leftboundary(root->left, res);
        }
        else if(root->right){
            leftboundary(root->right, res);
        }
    }
    
    void leaf(Node* root, vector<int>& res){
        if(root==NULL){
            return;
        }
        
        if(isLeaf(root)){
            res.push_back(root->data);
            return;
        }
        
        leaf(root->left, res);
        leaf(root->right, res);
        
    }
    
    void rightboundary(Node *root, vector<int>& res){
        if(root==NULL || isLeaf(root)){
            return;
        }
        
        if(root->right){
            rightboundary(root->right, res);
        }
        else if(root->left){
            rightboundary(root->left, res);
        }
        
        res.push_back(root->data);
    }
    
    vector<int> boundaryTraversal(Node *root) {
        vector<int> res;
        
        if(root==NULL) return res;
        if(!isLeaf(root)){
            res.push_back(root->data);
        }
        
        leftboundary(root->left, res);
        leaf(root, res);
        rightboundary(root->right, res);
        
        return res;
    }
};
