/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start
#include <stack>

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        val.push(x);
        if (min.empty() || x < min.top()) min.push(x);
        else min.push(min.top());
    }
    
    void pop() {
        val.pop();
        min.pop();
    }
    
    int top() {
        return val.top();
    }
    
    int getMin() {
        return min.top();
    }
private:
    std::stack<int> val, min;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

