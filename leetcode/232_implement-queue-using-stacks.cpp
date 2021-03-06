//Implement the following operations of a queue using stacks.
//
//    push(x) -- Push element x to the back of queue.
//    pop() -- Removes the element from in front of queue.
//    peek() -- Get the front element.
//    empty() -- Return whether the queue is empty.
//Notes:
//    You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
//    Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
//    You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).

#include <iostream>
#include <stack>

using namespace std;

// My own
// Time:	O(n)
// Space:	O(1)
class MyQueue {
    stack<int> stk1, stk2;
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        while (!stk1.empty()) {
            int val = stk1.top();
            stk1.pop();
            stk2.push(val);
        }
        stk1.push(x);
        while (!stk2.empty()) {
            int val = stk2.top();
            stk2.pop();
            stk1.push(val);
        }
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int val = stk1.top();
        stk1.pop();
        return val;
    }

    /** Get the front element. */
    int peek() {
        return stk1.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return stk1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */