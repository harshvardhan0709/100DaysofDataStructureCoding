#include<iostream>
#include<stack>

using namespace std;

void showStack(stack<int> s){
    while(!s.empty()){
        cout<<s.top()<<"\t";
        s.pop();
    }
    cout<<"\n";
}

int main(){
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    showStack(s);
    return 0;
}