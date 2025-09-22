/*
class Node
{
    public:
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void inorder(Node* root, vector<Node*>& v, vector<Node*>& vis){
        if(root==NULL) return;
        
        inorder(root->left, v, vis);
        
        if(vis.size()>0 && (root->data)<(vis.back()->data) && v[0]==NULL && v[1]==NULL){
            v[0]=vis.back();
            v[1]=root;
        }
        
        if(vis.size()>0 && (root->data)<(vis.back()->data) && v[0]!=NULL){
            v[2]=root;
        }
        
        vis.push_back(root);
        inorder(root->right, v, vis);
    }
    
    void correctBST(Node* root) {
        vector<int> inorderElements;
        vector<Node*> v(3, NULL);
        vector<Node*> vis;
        
        
        inorder(root, v, vis);
        if(v[2]==NULL){
            int temp=v[0]->data;
            v[0]->data=v[1]->data;
            v[1]->data=temp;
        }
        else{
            int temp=v[0]->data;
            v[0]->data=v[2]->data;
            v[2]->data=temp;
            
        }
    }
};
