// Infix to Postfix Conversion - Convert infix expressions to postfix using stack and operator precedence

#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <unordered_map>
using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

string infixToPostfix(const string &infix) {
    stack<char> stack;
    string postfix;

    for (char c : infix) {
            if (isalnum(c)) {
            postfix += c;
        }
            else if (c == '(') {
            stack.push(c);
        }
            else if (c == ')') {
            while (!stack.empty() && stack.top() != '(') {
                postfix += stack.top();
                stack.pop();
            }
            stack.pop();
        }
        else if (isOperator(c)) {
            while (!stack.empty() && precedence(stack.top()) >= precedence(c)) {
                postfix += stack.top();
                stack.pop();
            }
            stack.push(c);
        }
    }

    while (!stack.empty()) {
        postfix += stack.top();
        stack.pop();
    }

    return postfix;
}

int main() {
    string infix;

    infix = "((A+B)-C*(D/E))+F";
    string postfix = infixToPostfix(infix);
    
    cout << "Infix: " << infix << endl;
    cout << "Postfix: " << postfix << endl;

    return 0;
}