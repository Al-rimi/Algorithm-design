#include <stdio.h>
#include <string.h>
#include <iostream>
#include <stack>

using namespace std;

stack<int> OPND;  // Stack to store operands (numbers)
stack<char> OPTR; // Stack to store operators (+, -, *, /, etc.)

int precede(char x, char y);          // Function to compare precedence of operators
int operate(int a, char b, int c);    // Function to perform arithmetic operations
int calculate(char S[]);              // Function to evaluate the infix expression
void displaySignature(void);          // Function to display a special title

int main() {
    displaySignature();

    char S[100];
    printf("Please enter the infix expression: ");
    fgets(S, 100, stdin);  // Safer alternative to gets

    int result = calculate(S); 

    printf("Result: \033[33m%d\033[0m\n", result); 

    return 0;
}

int precede(char x, char y) {
    // Function to determine precedence between two operators
    // Returns 1 if x > y, 0 if x == y, and -1 if x < y

    int i, j;
    char pre[7][7] = {
        {'>', '>', '<', '<', '<', '>', '>'},
        {'>', '>', '<', '<', '<', '>', '>'},
        {'>', '>', '>', '>', '<', '>', '>'},
        {'>', '>', '>', '>', '<', '>', '>'},
        {'<', '<', '<', '<', '<', '=', ' '},
        {'>', '>', '>', '>', ' ', '>', '>'},
        {'<', '<', '<', '<', '<', ' ', '='}
    };

    switch (x) {
        case '+': i = 0; break;
        case '-': i = 1; break;
        case '*': i = 2; break;
        case '/': i = 3; break;
        case '(': i = 4; break;
        case ')': i = 5; break;
        case '\n': i = 6; break;  // check for newline character
    }

    switch (y) {
        case '+': j = 0; break;
        case '-': j = 1; break;
        case '*': j = 2; break;
        case '/': j = 3; break;
        case '(': j = 4; break;
        case ')': j = 5; break;
        case '\n': j = 6; break;  // check for newline character
    }

    if (pre[i][j] == '>') return 1;
    else if (pre[i][j] == '=') return 0;
    else return -1;
}

int operate(int a, char b, int c) {
    // Function to perform basic arithmetic operations
    if (b == '+')
        return c + a;
    if (b == '-')
        return c - a;
    if (b == '*')
        return c * a;  
    if (b == '/')
        return c / a;
    return 0;
}

int calculate(char S[]) {
    int a, c;
    char b;

    OPTR.push('\n');  // Push newline character to the operator stack as a boundary marker
    int i = 0;

    while (S[i] != '\n' || OPTR.top() != '\n') {  
        // Loop until both the input and stack have reached the boundary marker (newline character)
        if (S[i] >= '0' && S[i] <= '9') {
            int number = 0;

            // Convert sequence of digits to an integer
            while (S[i] >= '0' && S[i] <= '9') {
                number = number * 10 + S[i] - '0';
                i++;
            }
            OPND.push(number);  // Push the number to the operand stack
        } else {
            switch (precede(OPTR.top(), S[i])) {
                case -1:  
                    // If the precedence of the current operator is higher, push it onto the stack
                    OPTR.push(S[i]);
                    i++;
                    break;
                case 0:
                    // If the precedence is equal, pop the operator from the stack
                    OPTR.pop();
                    i++;
                    break;
                case 1:
                    // If the precedence of the current operator is lower, perform the operation
                    a = OPND.top();
                    OPND.pop();
                    c = OPND.top();
                    OPND.pop();
                    b = OPTR.top();
                    OPTR.pop();
                    OPND.push(operate(a, b, c));  // Push the result back to the operand stack
                    break;
                default:
                    break;
            }
        }
    }

    return OPND.top();  // The final result is the only element left in the operand stack
}

// Function to display a signature graphic
void displaySignature()
{
    const char *signature = R"(                                                                                      
  _____        __ _        ______                              _               ______          _             _   _
 |_   _|      / _(_)      |  ____|                            (_)             |  ____|        | |           | | (_)
   | |  _ __ | |_ ___  __ | |__  __  ___ __  _ __ ___  ___ ___ _  ___  _ __   | |____   ____ _| |_   _  __ _| |_ _  ___  _ __
   | | | '_ \|  _| \ \/ / |  __| \ \/ / '_ \| '__/ _ \/ __/ __| |/ _ \| '_ \  |  __\ \ / / _` | | | | |/ _` | __| |/ _ \| '_ \
  _| |_| | | | | | |>  <  | |____ >  <| |_) | | |  __/\__ \__ \ | (_) | | | | | |___\ V / (_| | | |_| | (_| | |_| | (_) | | | |
 |_____|_| |_|_| |_/_/\_\ |______/_/\_\ .__/|_|  \___||___/___/_|\___/|_| |_| |______\_/ \__,_|_|\__,_|\__,_|\__|_|\___/|_| |_|
                                      | |
                                      |_|
)";

    std::cout 
				<< "\033[90mName: AL RAIMI ABDULLAH\033[0m\n"
				<< "\033[90mID:   202336020211\033[0m"
				<< "\033[31m" << signature << "\033[0m"
				<< std::endl; // Display the signature in the terminal
}