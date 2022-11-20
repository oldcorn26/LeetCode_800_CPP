#include <iostream>

using namespace std;

struct MyList {
    int val;
    MyList *next;

    MyList(int value) : val(value), next(nullptr) {}

    MyList(int value, MyList *nxt) : val(value), next(nxt) {}
};

class MinStack {
private:
    int min;
    MyList *head;
public:
    MinStack() : min(INT32_MAX), head(nullptr) {

    }

    void push(int val) {
        if (head) {MyList *temp = new MyList(val, head); head = temp;}
        else head = new MyList(val);

        min = val < min ? val : min;
    }

    void pop() {
        MyList *temp = head;
        head = head->next;
        if (!head) {min = INT32_MAX, head = nullptr;}
        else if (min == temp->val) {
            min = head->val;
            while (head) {
               min = head->val < min ? head->val : min;
               head = head->next;
            }
        }
        head = temp->next;
        delete temp;
    }

    int top() {
        return head ? head->val : 0;
    }

    int getMin() {
        return min;
    }
};

int main() {
    MinStack *obj = new MinStack();
    obj->push(2);
    obj->push(0);
    obj->push(3);
    obj->push(0);
    int min = obj->getMin();
    obj->pop();
    min = obj->getMin();
    obj->pop();
    min = obj->getMin();
    obj->pop();
    min = obj->getMin();
    return 0;
}
