/*

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void traversal(Node* root, vector<int>& v){
        if(root==NULL) return;
        
        traversal(root->left,v);
        v.push_back(root->data);
        traversal(root->right, v);
    }
    
    int kthSmallest(Node *root, int k) {
        vector<int> v;
        
        traversal(root,v);
        if(k>v.size()) return -1;
        return v[k-1];
    }
};
