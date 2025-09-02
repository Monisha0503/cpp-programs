#include <iostream>
#include <cstring>
#include <cctype>
#include <cmath>
using namespace std;

#define MAX 100

// Character stack for operators
struct CharStack {
    char arr[MAX];
    int top;
} stc;

// Integer stack for evaluation
struct IntStack {
    int arr[MAX];
    int top;
} sti;

// Initialize stacks
void initCharStack() { stc.top = -1; }
void initIntStack() { sti.top = -1; }

// Char stack operations
bool isEmptyChar() { return (stc.top == -1); }
void pushChar(char c) { stc.arr[++stc.top] = c; }
char popChar() { return stc.arr[stc.top--]; }
char peekChar() { return stc.arr[stc.top]; }

// Int stack operations
bool isEmptyInt() { return (sti.top == -1); }
void pushInt(int val) { sti.arr[++sti.top] = val; }
int popInt() { return sti.arr[sti.top--]; }

// Operator precedence
int precedence(char op) {
    switch (op) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

// Infix → Postfix conversion
void infixToPostfix(char infix[], char postfix[]) {
    initCharStack();
    int i = 0, k = 0;
    char symbol;
    
    while ((symbol = infix[i++]) != '\0') {
        switch (symbol) {
            // If operand, add to postfix
            case '0' ... '9':
            case 'A' ... 'Z':
            case 'a' ... 'z':
                postfix[k++] = symbol;
                break;

            case '(':
                pushChar(symbol);
                break;

            case ')':
                while (!isEmptyChar() && peekChar() != '(')
                    postfix[k++] = popChar();
                popChar(); // discard '('
                break;

            // Operator
            default:
                while (!isEmptyChar() && precedence(peekChar()) >= precedence(symbol))
                    postfix[k++] = popChar();
                pushChar(symbol);
        }
    }

    // Pop remaining operators
    while (!isEmptyChar())
        postfix[k++] = popChar();

    postfix[k] = '\0';  // null terminate
}

// Postfix evaluation using switch
int evaluatePostfix(char postfix[]) {
    initIntStack();

    for (int i = 0; postfix[i] != '\0'; i++) {
        char symbol = postfix[i];
        
        if (isdigit(symbol)) {
            pushInt(symbol - '0');  // convert char → int
        } else {
            int op1 = popInt();
            int op2 = popInt();
            int res;

            switch (symbol) {
                case '+': res = op2 + op1; break;
                case '-': res = op2 - op1; break;
                case '*': res = op2 * op1; break;
                case '/': res = op2 / op1; break;
                case '^': res = pow(op2, op1); break;
                default: res = 0;
            }
            pushInt(res);
        }
    }
    return popInt();
}

// Main
int main() {
    char infix[MAX], postfix[MAX];
    
    cout << "Enter Infix Expression (single-digit numbers only): ";
    cin >> infix;

    infixToPostfix(infix, postfix);
    cout << "Postfix Expression: " << postfix << endl;

    int result = evaluatePostfix(postfix);
    cout << "Evaluated Result: " << result << endl;

    return 0;
}