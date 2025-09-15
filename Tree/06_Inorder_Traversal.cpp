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
    void traversal(Node* root, vector<int>& ans){
        if(root==NULL) return;
        
        traversal(root->left, ans);
        ans.push_back(root->data);
        traversal(root->right, ans);
    }
   
    vector<int> inOrder(Node* root) {
        vector<int> ans;
        traversal(root, ans);
        return ans;
    }
};
