/*
class Node {
  public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
#include<bits/stdc++.h>
class Solution {
  public:
    Node* addTwoLists(Node* head1, Node* head2) {
        stack<int> st1, st2, res;
        Node *temp1=head1, *temp2=head2;
        
        while(temp1){
            st1.push(temp1->data);
            temp1=temp1->next;
        }
        
        while(temp2){
            st2.push(temp2->data);
            temp2=temp2->next;
        }
        
        int a,b, carry=0, sum=0;
        while(!st1.empty() && !st2.empty()){
            sum=0;
            a=st1.top();
            b=st2.top();
            sum=a+b+carry;
            
            if(sum>9){
                carry=1;
                res.push(sum%10);
            } 
            else{
                carry=0;
                res.push(sum);
            }
            
            st1.pop();
            st2.pop();
        }
        
        while(!st1.empty()){
            a=st1.top();
            sum=a+carry;
            
            if(sum>9){
                carry=1;
                res.push(sum%10);
            } 
            else{
                carry=0;
                res.push(sum);
            }
            
            st1.pop();
        }
        
        while(!st2.empty()){
            b=st2.top();
            sum=b+carry;
            
            if(sum>9){
                carry=1;
                res.push(sum%10);
            } 
            else{
                carry=0;
                res.push(sum);
            }
            
            st2.pop();
        }
        
        if(carry==1){
            res.push(carry);
        }
        
        while(!res.empty() && res.top()==0){
            res.pop();
        }
        
        if(res.size()==0) return new Node(0);
        
        Node* finalSum=new Node(res.top());
        Node* temp=finalSum;
        res.pop();
        
        while(!res.empty()){
            int e=res.top();
            temp->next=new Node(e);
            temp=temp->next;
            res.pop();
        }
        
        return finalSum;
        
    }
};
