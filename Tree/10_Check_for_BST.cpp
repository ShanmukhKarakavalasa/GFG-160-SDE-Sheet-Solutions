class Solution {
  public:
    void traversal(Node* root, vector<int>& v){
        if(root==NULL) return;
        
        traversal(root->left, v);
        v.push_back(root->data);
        traversal(root->right, v);
    }

    bool isBST(Node* root) {
        vector<int> v;
        traversal(root, v);
        for(int i=0;i<v.size()-1;i++){
            if(v[i]>v[i+1]) return false;
        }
        
        return true;
        
    }
};
