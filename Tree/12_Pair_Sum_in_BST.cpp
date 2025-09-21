/*
Node is as follows
class Node {
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
    bool search(Node *root, Node* node, int key){
        if(root==NULL) return false;
        
        if(root->data==key && node!=root) return true;
        if(root->data>key) return search(root->left, node, key);
        if(root->data<key) return search(root->right, node, key);
    }
    
    bool findTarget(Node *root, int target) {
        map<int, int> mp;
        int key;
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            Node* curr=q.front();
            q.pop();
            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
            
            key=target-(curr->data);
            if(mp.find(key)!=mp.end()) return true;
            
            mp[curr->data]++;
            if(search(root, root, key)) return true;
        }
        
        return false;
        
    }
};
