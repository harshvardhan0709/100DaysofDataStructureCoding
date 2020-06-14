#include<iostream>
#include<stack>
#include<string>

using namespace std;

bool isOperator(char c){
    switch(c){
        case '^':
        case '*':
        case '/':
        case '+':
        case '-':
            return true;
    }
    return false;
}

string postfixToInfix(string exp){
    stack<string> s;
    int l = exp.size();

    for(int i=0; i < l; i++){
        if(isOperator(exp[i])){
            string op1 = s.top(); s.pop();
            string op2 = s.top(); s.pop();

            string temp = "("+op2+exp[i]+op1+")";
            s.push(temp);
        }
        else{
            s.push(string(1, exp[i]));
        }
    }

    return s.top();
}

int main(){
    string exp = "ab*c+";
    cout<< "Infix: "<< postfixToInfix(exp);
    return 0;
}