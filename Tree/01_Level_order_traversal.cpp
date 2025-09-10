/* A binary tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<vector<int>> levelOrder(Node *root) {
        vector<vector<int>> ans;
        vector<int> temp;
        int level=0;
        queue<Node*> q;
        
        q.push(root);
        while(!q.empty()){
            vector<int> temp;
            for(int i=0;i<q.size();i++){
                Node* curr=q.front();
                temp.push_back(curr->data);
                q.pop();
                
                if(curr->left){
                    q.push(curr->left);
                }
                
                if(curr->right){
                    q.push(curr->right);
                }
            }
            ans.push_back(temp);
        }
        
        return ans;
        
    }
};
