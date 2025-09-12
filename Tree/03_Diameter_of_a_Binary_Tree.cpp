/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* newNode(int val) {
    return new Node(val);
}
*/

class Solution {
  public:  
    int find(Node* node, int &maxi){
        if(node==NULL) return 0;
        int left=find(node->left, maxi);
        int right=find(node->right, maxi);
        
        maxi=max(maxi, left+right); //stores maximum diameter
        return 1+max(left, right); //returns the height
    }
    
    int diameter(Node* root) {
        int maxi=INT_MIN;
        find(root, maxi);
        return maxi;
    }
};
