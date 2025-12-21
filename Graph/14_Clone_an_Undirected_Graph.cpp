// struct Node {
//     int val;
//     vector<Node*> neighbors;
//     Node() {
//         val = 0;
//         neighbors = vector<Node*>();
//     }
//     Node(int _val) {
//         val = _val;
//         neighbors = vector<Node*>();
//     }
//     Node(int _val, vector<Node*> _neighbors) {
//         val = _val;
//         neighbors = _neighbors;
//     }
// };

class Solution {
  public:
    Node* dfs(Node* node, map<Node*, Node*>& mp){
        if(mp.find(node)!=mp.end()){
            return mp[node];
        }
        
        Node* clone=new Node(node->val);
        mp[node]=clone;
        
        for(Node* adj: node->neighbors){
            (clone->neighbors).push_back(dfs(adj, mp));
        }
        
        return mp[node];
    }
    
    Node* cloneGraph(Node* node) {
        map<Node*, Node*> mp; //original- clone
        
        if(node==NULL) return NULL;
        return dfs(node, mp);
        
    }
};
