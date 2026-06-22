// infix to postfix conversion

#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int prec(char x){
    if(x == '^')
        return 2;
    else if(x == '*' || x == '/' || x == '%')
        return 1;
    else if(x == '+' || x == '-')
        return 0;
    else
        return -1;
}

int main(){

    string x;

    cout << "Enter infix expression: ";
    cin >> x;

    vector<char> postfix;
    stack<char> s;

    for(int i = 0; i < x.length(); i++){

        if(prec(x[i]) == -1 && x[i] != '(' && x[i] != ')'){
            postfix.push_back(x[i]);
        }

        else if(x[i] == '('){
            s.push(x[i]);
        }

        else if(x[i] == ')'){

            while(!s.empty() && s.top() != '('){
                postfix.push_back(s.top());
                s.pop();
            }

            if(!s.empty())
                s.pop();
        }

        else{

            while(!s.empty() &&
                  s.top() != '(' &&
                  prec(s.top()) >= prec(x[i])){
                postfix.push_back(s.top());
                s.pop();
            }

            s.push(x[i]);
        }
    }

    while(!s.empty()){
        postfix.push_back(s.top());
        s.pop();
    }

    cout << "Postfix: ";

    for(char c : postfix)
        cout << c;

    cout << endl;

    return 0;
}