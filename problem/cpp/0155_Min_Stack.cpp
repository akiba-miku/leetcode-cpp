#include <stack>

using namespace std;
class MinStack
{
private:
    stack<int> st_;
    stack<int> min_st_;
public:
    MinStack()
    {
    }

    void push(int val)
    {
        st_.push(val);
        if(min_st_.empty() || min_st_.top() >= val) {
            min_st_.push(val);
        }
    }

    void pop()
    {
        if(st_.top() == min_st_.top()) min_st_.pop();
        st_.pop();
    }

    int top()
    {
        return st_.top();
    }

    int getMin()
    {
        return min_st_.top();
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