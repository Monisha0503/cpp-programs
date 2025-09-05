#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <cstdlib>
using namespace std;

#define MAX 100

string infix, postfix;

int precedence(char symbol) {
    switch (symbol) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default:  return 0;
    }
}

bool isSpace(char c) {
    return (c == ' ' || c == '\t');
}

void infixToPostfix() {
    stack<char> st;
    postfix = "";
    
    for (size_t i = 0; i < infix.length(); i++) {
        char symbol = infix[i];
        if (!isSpace(symbol)) {
            if (isdigit(symbol)) {
                // read full number
                while (i < infix.length() && isdigit(infix[i])) {
                    postfix += infix[i++];
                }
                postfix += ' '; // delimiter
                i--; // step back
            } else {
                switch (symbol) {
                    case '(':
                        st.push(symbol);
                        break;
                    case ')':
                        while (!st.empty() && st.top() != '(') {
                            postfix += st.top();
                            postfix += ' ';
                            st.pop();
                        }
                        if (!st.empty()) st.pop(); // remove '('
                        break;
                    case '+': case '-': case '*': case '/': case '^':
                        while (!st.empty() && precedence(st.top()) >= precedence(symbol)) {
                            postfix += st.top();
                            postfix += ' ';
                            st.pop();
                        }
                        st.push(symbol);
                        break;
                    default:
                        cout << "\nInvalid symbol: " << symbol << endl;
                        exit(1);
                }
            }
        }
    }
    while (!st.empty()) {
        postfix += st.top();
        postfix += ' ';
        st.pop();
    }
}

int evaluatePostfix() {
    stack<int> evalStack;
    for (size_t i = 0; i < postfix.length(); ) {
        if (isdigit(postfix[i])) {
            string num = "";
            while (i < postfix.length() && isdigit(postfix[i])) {
                num += postfix[i++];
            }
            evalStack.push(stoi(num));
        } else if (postfix[i] == ' ') {
            i++;
        } else {
            int op2 = evalStack.top(); evalStack.pop();
            int op1 = evalStack.top(); evalStack.pop();
            int result;
            switch (postfix[i]) {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/':
                    if (op2 == 0) {
                        cout << "\nError: Division by zero\n";
                        exit(1);
                    }
                    result = op1 / op2; break;
                case '^':
                    result = 1;
                    for (int k = 0; k < op2; k++)
                        result *= op1;
                    break;
                default:
                    cout << "\nInvalid operator: " << postfix[i] << endl;
                    exit(1);
            }
            evalStack.push(result);
            i++;
        }
    }
    return evalStack.top();
}

int main() {
    cout << "Enter the Infix Expression: ";
    getline(cin, infix);

    infixToPostfix();
    cout << "\nThe equivalent Postfix Expression: " << postfix << endl;

    int result = evaluatePostfix();
    cout << "Evaluation Result: " << result << endl;

    return 0;
}