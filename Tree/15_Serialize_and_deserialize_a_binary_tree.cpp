/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

class Solution {
  public:
    void traversal(Node* root, vector<int>& res){
        if(root==NULL){
            res.push_back(-1);
            return;
        }
        
        res.push_back(root->data);
        traversal(root->left, res);
        traversal(root->right, res);
        
    }
    vector<int> serialize(Node *root) {
        vector<int> res;
        traversal(root, res);
        return res;
        
    }
    
    Node* deseri(vector<int>& arr, int& index){
        if(index==arr.size() || arr[index]==-1){
            index++;
            return NULL;
        }
        
        Node* root=new Node(arr[index++]);
        root->left=deseri(arr, index);
        root->right=deseri(arr, index);
        
        return root;
    }
    
    Node *deSerialize(vector<int> &arr) {
        int index=0;
        return deseri(arr, index);
    }
};
