/*

Link: https://leetcode.com/problems/min-stack/description/

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.


*/

class MinStack {
    public:
    
       vector<pair<int,int>> stack; // will store present value and min value at particular insertion
        MinStack() {
            
        }
        
        void push(int val) {
            if(stack.empty())
                stack.push_back({val,val});
            else
                stack.push_back({val, min(val,stack.back().second)});
        }
        
        void pop() {
            stack.pop_back();
            
        }
        
        int top() {
            return stack.back().first;
        }
        
        int getMin() {
            return stack.back().second;
        }
    };
    
    /**
     * Your MinStack object will be instantiated and called as such:
     * MinStack* obj = new MinStack();
     * obj->push(val);
     * obj->pop();
     * int param_3 = obj->top();
     * int param_4 = obj->getMin();
     */