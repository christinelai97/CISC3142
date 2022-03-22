#include <iostream>
#include <cmath>
using namespace std;

double a;
double b;
double answer;
char char_Operator;

enum class Operation { Add, Subtract, Multiply, Divide, Exponent, Sqrt, Invalid };

struct Calculator {

    Operation op;

    Calculator(Operation operation) {
      op = operation;
    }

    int calc(double a, double b) {
        switch (op) {
            case Operation::Add: {
                return a + b;
            } break;
            case Operation::Subtract: {
                return a - b;
            } break;
            case Operation::Multiply: {
                return a * b;
            } break;
            case Operation::Divide: {
                return a / b;
            } break;
            case Operation::Sqrt: {
                return sqrt(a)+b;
            } break;
            case Operation::Exponent: {
                return pow(a, b);
            } break;
            case Operation::Invalid: {
                cout << "Error: invalid operation!\n";
                return 0;
            }
        }
    }
};

int main() {

    int numOfOperations;

    cout << "How many Operations would you like to perform?\n";
    cin >> numOfOperations;

    //For single operations
    if (numOfOperations == 1) {

      //cout << "Please provide an integer.\n";
      //cin >> a;
      cout << "\nEnter a calculation: [eg. Addition: 4 + 3, Sqrt: 9$, Exponent: 5^2 ]\n";
      cout << "Choose an Operation: [Add '+', Subtract '-', Multiply '*', Divide '/', Exponent '^' Sqrt '$', ]\n";
      cin >> a >> char_Operator;

      //User Inputs the designated operation symbol

      //cin >> char_Operator;

      //User Inputs second number if Square Root is not chosen
      if (char_Operator != '$') {
        //cout << "Please provide another integer.\n";
        cin >> b;
      }

      //If Square root operation chosen, second input is assigned 0
      else {
        b = 0;
      }

      //null Operation
      Operation op{};

      //converts char to designated Operation in enum
      if (char_Operator == '+') {
        op = Operation::Add;
      }
      else if (char_Operator == '-') {
        op = Operation::Subtract;
      }
      else if (char_Operator == '*') {
        op = Operation::Multiply;
      }
      else if (char_Operator == '/') {
        op = Operation::Divide;
      }
      else if (char_Operator == '^') {
        op = Operation::Exponent;
      }
      else if (char_Operator == '$') {
        op = Operation::Sqrt;
      }
      else {
        op = Operation::Invalid;
      }

      Calculator input = Calculator(op);

      answer = input.calc(a, b);

      cout << "\nThe Answer is " << answer << "\n";

    }

    //For multiple operations
    else if (numOfOperations>=2) {

      //User inputs the first number
      cout << "\nEnter a calculation: [eg. Addition: 4 + 3, Sqrt: 9$, Exponent: 5^2 ]\n";
      cout << "Choose an Operation: [Add '+', Subtract '-', Multiply '*', Divide '/', Exponent '^' Sqrt '$', ]\n";
      cin >> a >> char_Operator;

      //User Inputs the designated operation symbol

      //cin >> char_Operator;

      //User Inputs second number if Square Root is not chosen
      if (char_Operator != '$') {
        //cout << "Please provide another integer.\n";
        cin >> b;
      }

      //If Square root operation chosen, second input is assigned 0
      else {
        b = 0;
      }

      //null Operation
      Operation op{};

      //converts char to designated Operation in enum
      if (char_Operator == '+') {
        op = Operation::Add;
      }
      else if (char_Operator == '-') {
        op = Operation::Subtract;
      }
      else if (char_Operator == '*') {
        op = Operation::Multiply;
      }
      else if (char_Operator == '/') {
        op = Operation::Divide;
      }
      else if (char_Operator == '^') {
        op = Operation::Exponent;
      }
      else if (char_Operator == '$') {
        op = Operation::Sqrt;
      }
      else {
        op = Operation::Invalid;
      }

      Calculator input = Calculator(op);

      answer = input.calc(a, b);
      double currentResult = answer;

      cout << "\nThe current answer is: " << answer << "\n";

      for (int i=numOfOperations-1; i > 0; i--) {
        cout << "\nChoose an Operation followed by a number:\n"
        <<"[Add '+', Subtract '-', Multiply '*', Divide '/', Sqrt '$']\n"
        << "Number of Operations left: " << i << "\n"
        << currentResult << " ";
        cin >> char_Operator;

        //User Inputs second number if Square Root is not chosen
        if (char_Operator != '$') {
          //cout << "\nEnter a second number:\n";
          cin >> b;
        }

        //If Square root operation chosen, second input is assigned 0
        else {
          b = 0;
        }

        //null Operation
        Operation op{};

        //converts char to designated Operation in enum
        if (char_Operator == '+') {
          op = Operation::Add;
        }
        else if (char_Operator == '-') {
          op = Operation::Subtract;
        }
        else if (char_Operator == '*') {
          op = Operation::Multiply;
        }
        else if (char_Operator == '/') {
          op = Operation::Divide;
        }
        else if (char_Operator == '^') {
          op = Operation::Exponent;
        }
        else if (char_Operator == '$') {
          op = Operation::Sqrt;
        }
        else {
          op = Operation::Invalid;
        }

        Calculator input = Calculator(op);

        answer = input.calc(currentResult, b);
        currentResult = answer;

        if (i == 1) {
          cout << "\nThe final answer is " << answer << "\n";
        }
        else {
          cout << "\nThe current answer is " << answer << "\n";
        }
      }
    }


}
