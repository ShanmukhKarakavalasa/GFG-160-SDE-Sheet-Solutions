class Solution {
  public:
    stack<int> st;
    stack<int> mini;
    Solution() {
        
    }

    // Add an element to the top of Stack
    void push(int x) {
        if(mini.empty()){
            st.push(x);
            mini.push(x);
        }
        else{
            mini.push(min(mini.top(), x));
            st.push(x);
        }
        
    }

    // Remove the top element from the Stack
        
    void pop() {
        if(st.empty()){
            return;
        }
        
        if(st.top()!=mini.top()){
            st.pop();
        }
        else{
            while(!mini.empty() && mini.top()==st.top()){
                mini.pop();
            }
            
            st.pop();
        }
    }

        
    // Returns top element of the Stack
    int peek() {
        if(st.empty()){
            return -1;
        }
        
        return st.top();
    }
        

    // Finds minimum element of Stack
    int getMin() {
        if(st.empty()){
            return -1;
        }
        return mini.top();
    }
};
