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
    int traverse(Node* root, int k, map<int, int>& mp, int curSum){
        if(root==NULL) return 0;
        
        int paths=0;
        curSum+=root->data;
        
        if(curSum==k) paths++;
        paths+=mp[curSum-k];
        
        mp[curSum]++;
        paths+=traverse(root->left, k, mp, curSum);
        paths+=traverse(root->right, k, mp, curSum);
        mp[curSum]--;
        
        return paths;
    }
    
    int sumK(Node *root, int k) {
        map<int, int> mp;
        
        return traverse(root, k, mp, 0);
        
    }
};
