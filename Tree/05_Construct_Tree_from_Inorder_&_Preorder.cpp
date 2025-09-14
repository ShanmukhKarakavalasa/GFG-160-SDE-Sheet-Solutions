// Class that contains the logic to build the binary tree
/*
Definition of the Node class
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution {
  public:
    Node* make_tree(int l, int r, vector<int> &preorder, map<int, int>& mp, int& cur_index){
        if(l>r) return nullptr;
        
        int val=preorder[cur_index];
        cur_index++;
        
        Node* node=new Node(val);
        node->left=make_tree(l, mp[val]-1, preorder, mp, cur_index);
        node->right=make_tree(mp[val]+1, r, preorder, mp, cur_index);
        
        return node;
    }
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        int n=inorder.size();
        int cur_index=0;
        map<int, int> mp;
        
        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }
        
        return make_tree(0, n-1, preorder, mp, cur_index);
        
    }
};
