/*Christine Lai
This program creates a user-defined calculator struct with an Operator enum,
and uses a switch statement to perform the designated operation chosen by the user.

The user inputs a linear calculation such as: a + b, 5 * 5, etc. using designated
char symbols for the available operations.

The user may choose between a single operation, or to input multiple operations

Available operations are: Addition, Subtraction, Multiplication, Division, Square root, Exponents

Makefile available in root directory
*/

#include <iostream>
#include <cmath>
using namespace std;

//input variables
float a;
float b;
float answer;
char char_Operator;

//enum for available operations
enum class Operation { Add, Subtract, Multiply, Divide, Exponent, Sqrt, Invalid };

//struc for Calculator
struct Calculator {

    Operation op;

    //takes user's selected operation and sets to local variable in Calculator struct
    Calculator(Operation operation) {
      op = operation;
    }

    //takes in user's entry and performs selected operation
    float calc(float a, float b) {
        switch (op) {
            case Operation::Add: { //Operation for Addition
                return a + b;
            } break;
            case Operation::Subtract: { //Operation for Subtraction
                return a - b;
            } break;
            case Operation::Multiply: { //Operation for Multiplication
                return a * b;
            } break;
            case Operation::Divide: { //Operation for Division
                return a / b;
            } break;
            case Operation::Sqrt: { //Operation for Square Root
                return sqrt(a)+b;
            } break;
            case Operation::Exponent: { //Operation for Exponents
                return pow(a, b);
            } break;
            case Operation::Invalid: { //Invalid Opertion returns first input
                cout << "\nError: Invalid operation!\n";
                cout << "Returning initial input..\n";
                return a;
            }
        }
    }
};

int main() {

    //Variable for number of operations to be performed
    int numOfOperations;

    //Asks user's input for number of operations to be performs
    cout << "How many Operations would you like to perform?\n";
    cin >> numOfOperations;

    //If user enters an invalid input
    if (cin.fail()) {
      cout << "\nError: User's input is Invalid.";
      return -1;
    }

    //For single operations
    if (numOfOperations == 1) {

      //Asks user to enter a calculation according to the format:
      //presents available operations
      cout << "\nEnter a Calculation: [eg. Add: 4 + 3, Square Root: 9$, Exponent: 5^2 ]\n";
      cout << "Available Operations are listed below:\n"
      << "----------------------------------------------------------------------------\n"
      << "Add '+', Subtract '-', Multiply '*', Divide '/', Exponent '^' Sqare Root '$'\n"
      << "----------------------------------------------------------------------------\n";
      cin >> a >> char_Operator;
      //If user inputs invalid Number
      if (cin.fail()) {
        cout << "\nError: User's input is invalid.";
        return -1;
      }

      //Allows user to input a second number if Square Root is not selected
      if (char_Operator != '$') {

        cin >> b;

        if (cin.fail()) {
          cout << "\nError: User's input is Invalid.";
          return -1;
        }
      }

      //If Square root operation chosen, second input is assigned 0
      else {
        b = 0;
      }

      //initialize variable op to allow char conversion
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

      //Asks user to enter a calculation according to the format:
      //presents available operations
      cout << "\nEnter a Calculation: [eg. Add: 4 + 3, Square Root: 9$, Exponent: 5^2 ]\n";
      cout << "Available Operations are listed below:\n"
      << "-----------------------------------------------------------------------------\n"
      << "Add '+', Subtract '-', Multiply '*', Divide '/', Exponent '^' Square Root '$'\n"
      << "-----------------------------------------------------------------------------\n";
      cin >> a >> char_Operator;

      if (cin.fail()) {
        cout << "\nError: User's input is Invalid.";
        return -1;
      }


      //Allows user to input a second number if Square Root is not selected
      if (char_Operator != '$') {

        cin >> b;

        if (cin.fail()) {
          cout << "\nError: User's input is Invalid.";
          return -1;
        }

      }

      //If Square root operation chosen, second input is assigned 0
      else {
        b = 0;
      }

      //initializes variable op to allow char conversion
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

      //Creates Calculator struc with user's selected operation
      Calculator user_operation = Calculator(op);

      answer = user_operation.calc(a, b);

      //current result is set to answer
      float currentResult = answer;

      //prints out the current answer
      cout << "\nThe current answer is: " << answer << "\n";

      //iterates until number of operations left is 0
      for (int i=numOfOperations-1; i > 0; i--) {
        cout << "\nEnter an Operation followed by a number:\n"
        <<"------------------------------------------------------------------------------\n"
        <<"Add '+', Subtract '-', Multiply '*', Divide '/', Exponent '^', Square Root '$'\n"
        <<"------------------------------------------------------------------------------\n"
        << "Number of Operations left: " << i << "\n"
        << currentResult << " ";
        cin >> char_Operator;

        if (cin.fail()) {
          cout << "\nUser's input is Invalid input!";
          return -1;
        }

        //Allows user to input second number is Square root is not chosen
        if (char_Operator != '$') {

          cin >> b;

          if (cin.fail()) {
            cout << "\nUser's input is Invalid input!";
            return -1;
          }

        }

        //If Square root operation chosen, second input is assigned 0
        else {
          b = 0;
        }

        //initializes op so that char symbols can be converted to designated operations
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

        //
        Calculator user_operation = Calculator(op);

        answer = user_operation.calc(currentResult, b);
        currentResult = answer;

        //prints out final answer if its the last number of operations
        if (i == 1) {
          cout << "\nThe final answer is " << answer << "\n";
        }
        //prints out current answer if there are still more operations
        else {
          cout << "\nThe current answer is " << answer << "\n";
        }
      }
    }


}
