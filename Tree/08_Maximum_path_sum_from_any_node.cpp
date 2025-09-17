// User Fuction template for C++
/*
// Tree Node
class Node {
public:
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
    int traverse(Node* root, int& maxi){
        if(root==NULL) return 0;
        
        int l=max(0,traverse(root->left, maxi));
        int r=max(0,traverse(root->right, maxi));
        int val=root->data;
        
        maxi=max(maxi, val+l+r);
        
        return val+max(l,r);
    }
    int findMaxSum(Node *root) {
        int maxi=INT_MIN;
        traverse(root, maxi);
        return maxi;
        
    }
};
