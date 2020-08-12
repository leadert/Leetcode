#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

class MinStack {
private:
    stack<int>  xStack;
    stack<int>  minStack;
public:
    /** initialize your data structure here. */
    MinStack() {};
    void push(int x);
    void pop();
    int top();
    int getMin();
};

void MinStack::push(int x) {
    xStack.push(x);
    if (!minStack.empty())  minStack.push(min(minStack.top(), x));
    else minStack.push(x);
}

void MinStack::pop() {
    xStack.pop();
    minStack.pop();
}

int MinStack::top() {
    return xStack.top();
}

int MinStack::getMin() {
    return minStack.top();
}
