// Advanced C++ Scientific Calculator
#include <iostream>
#include <cmath>
#include <limits>
using namespace std;

void clearCin() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    double num1, num2, result;
    char op;
    char cont = 'y';

    cout << "Advanced Scientific Calculator\n";
    while(cont == 'y' || cont == 'Y') {
        cout << "\nEnter operation (+, -, *, /, ^, s for sqrt, c for cos, t for tan, i for sin, l for log, n for ln): ";
        cin >> op;

        if(op == 's') { // sqrt
            cout << "Enter number: ";
            cin >> num1;
            if(num1 < 0) {
                cout << "Error: Negative input for square root!" << endl;
            } else {
                cout << "Result: " << sqrt(num1) << endl;
            }
        } else if(op == 'c' || op == 't' || op == 'i') { // trig functions
            cout << "Enter angle in degrees: ";
            cin >> num1;
            double rad = num1 * M_PI / 180.0;
            if(op == 'c') cout << "Result: " << cos(rad) << endl;
            else if(op == 't') cout << "Result: " << tan(rad) << endl;
            else if(op == 'i') cout << "Result: " << sin(rad) << endl;
        } else if(op == 'l' || op == 'n') { // log and ln
            cout << "Enter number: ";
            cin >> num1;
            if(num1 <= 0) {
                cout << "Error: Non-positive input for logarithm!" << endl;
            } else {
                if(op == 'l') cout << "Result: " << log10(num1) << endl;
                else cout << "Result: " << log(num1) << endl;
            }
        } else { // basic operations
            cout << "Enter first number: ";
            cin >> num1;
            cout << "Enter second number: ";
            cin >> num2;

            switch(op) {
                case '+': result = num1 + num2; break;
                case '-': result = num1 - num2; break;
                case '*': result = num1 * num2; break;
                case '/':
                    if(num2 == 0) {
                        cout << "Error: Division by zero!" << endl;
                        continue;
                    } else {
                        result = num1 / num2;
                    }
                    break;
                case '^': result = pow(num1, num2); break;
                default:
                    cout << "Invalid operator!" << endl;
                    continue;
            }
            cout << "Result: " << result << endl;
        }

        cout << "\nDo you want to perform another calculation? (y/n): ";
        cin >> cont;
        clearCin();
    }

    return 0;
}
