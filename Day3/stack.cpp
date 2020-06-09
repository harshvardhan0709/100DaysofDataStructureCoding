#include<iostream>
#define MAX 100
using namespace std;

class Stack{
    int top;
    public:
        int arr[MAX];
        Stack(){top = -1;};
        bool push(int x);
        int pop();
        int peek();
        bool isEmpty();
};

bool Stack::push(int x){
    if(top > MAX-1){
        cout<< "Stack Overflow\n";
        return false;
    }
    else{
        arr[++top] = x;
        cout<< x << " pushed to stack\n";
        return true;
    }
}

int Stack::pop(){
    if(top < 0){
        cout<< "Stack Underflow\n";
        return 0;
    }
    else{
        int x = arr[top--];
        return x;
    }
}

int Stack::peek(){
    if(top < 0){
        cout<< "STack Underflow\n";
        return 0;
    }
    else{
        int x = arr[top];
        return x;
    }
}

bool Stack::isEmpty(){
    return (top<0);
}

int main(){
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    cout<<s.pop()<<" popped from stack\n";
    return 0;
}