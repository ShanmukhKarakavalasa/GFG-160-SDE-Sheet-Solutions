/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    int find_height(Node* node){
        if(node==NULL) return -1;
        
        return 1+max(find_height(node->left), find_height(node->right));
    }
    
    int height(Node* node) {
        int res=0;
        res=find_height(node);
        return res;
        
    }
};
