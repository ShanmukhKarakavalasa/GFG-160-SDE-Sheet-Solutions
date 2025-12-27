class Node{
    public:
    Node* zero;
    Node* one;
    
    Node(){
        zero=NULL;
        one=NULL;
    }
};

class Trie{
    public:
    Node* root;
    
    Trie(){
        root=new Node();
    }
    
    void insert(int n){
        Node* curr=root;
        
        for(int i=31;i>=0;i--){
            int bit=(n>>i) & 1;
            
            if(bit==0){
                if(!curr->zero){
                    curr->zero=new Node();
                }
                
                curr=curr->zero;
                
            }
            
            else{
                if(!curr->one){
                    curr->one=new Node();
                }
                
                curr=curr->one;
                
            }
        }
    }
    
    int findXOR(int n){
        int res=0;
        Node* curr=root;
        
        for(int i=31;i>=0;i--){
            int bit=(n>>i) & 1;
            
            if(bit==0){
                if(curr->one){
                    curr=curr->one;
                    res+=(1<<i);
                }
                else{
                    curr=curr->zero;
                }
            }
            
            else{
                if(curr->zero){
                    curr=curr->zero;
                    res+=(1<<i);
                }
                else{
                    curr=curr->one;
                }
            }
        }
        
        return res;
    }
};

class Solution {
  public:
    int maxXor(vector<int> &arr) {
        int res=0;
        Trie* t=new Trie();
        
        t->insert(arr[0]);
        
        for(int i=1;i<arr.size();i++){
            res=max(res, t->findXOR(arr[i]));
            t->insert(arr[i]);
        }
        
        return res;
    }
};
