#include<iostream>
#include<stack>
using namespace std;

class CQueue {
private:
    stack<int> InStack;
    stack<int> OutStack;

public:
    CQueue() {
        while (!InStack.empty()) {
            InStack.pop();
        }
        while (!OutStack.empty()) {
            OutStack.pop();
        }
    }

    void appendTail(int value) {
        InStack.push(value);
    }

    int deleteHead() {
        int topValue;
        while (!InStack.empty()) {
            topValue = InStack.top();
            InStack.pop();
            OutStack.push(topValue);
        }

        int ret = OutStack.top();
        OutStack.pop();
        while (!OutStack.empty()) {
            topValue = OutStack.top();
            OutStack.pop();
            InStack.push(topValue);
        }
        return ret;
    }
};


//int main(){
//    CQueue* a = new CQueue();
//    a->appendTail(3);
//    a->appendTail(1);
//    int ret = a->deleteHead();
//    cout << ret;
//    return 0;
//}