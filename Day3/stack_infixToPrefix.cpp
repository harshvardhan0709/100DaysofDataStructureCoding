#include<iostream>
#include<stack>
#include<string>

using namespace std;

int prec(char c){
    if(c == '^'){
        return 3;
    }
    else if(c == '*' || c == '/'){
        return 2;
    }
    else if(c == '+' || c == '-'){
        return 1;
    }
    else{
        return -1;
    }
}

string infixToPrefix(string exp){
    
}

int main(){
    string s = "(a-b/c)*(a/k-l)";
    cout<< infixToPrefix(s); 
    return 0;
}