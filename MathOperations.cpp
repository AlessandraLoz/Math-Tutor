#include "MathOperations.h"
#include <iomanip>

MathOperations::MathOperations()
{
    operand1 = 0;  // the first operand for basic math operation
    operand2 = 0;  // the second operand for basic math operation
    theoperator = ' '; // the current operator;
    answer = 0;
}

void MathOperations::setOperands(int op1, int op2)
{
    //assigns operators with random number generated in main function
    operand1 = op1;
    operand2 = op2;
}

char MathOperations::getOperator() const
{
    //returns current value of variable theoperator
    return theoperator;
}

int MathOperations::getAnswer() const
{
    //reutrns current value of variable answer
    return answer;
}

void MathOperations::Addition()
{
    //adds ranndom numbers and stores the reseult in answer variable 
    answer = operand1 + operand2;
    //assigns operator with according symbol
    theoperator = '+';
}

void MathOperations::Subtraction()
{
    //subtracts ranndom numbers and stores the reseult in answer variable 
    answer = operand1 - operand2;
    //assigns operator with according symbol
    theoperator = '-';
}

void MathOperations::Multiplication()
{
    //multiplies ranndom numbers and stores the reseult in answer variable 
    answer = operand1 * operand2;
    //assigns operator with according symbol
    theoperator = '*';
}

void MathOperations::Division()
{
    //divides ranndom numbers and stores the reseult in answer variable 
    answer = operand1 / operand2;
    //assigns operator with according symbol
    theoperator = DivisionSymbol;
}

bool MathOperations::checkAnswer(int response) const
{
    //returns true or false based on whether answer = response
    return answer == response;
}

void MathOperations::print() const
{
    //prints random number equation for user to practice operators
    cout << setw(5) << operand1 << endl;
    //calls getOperator function in order to use that operator to display
    getOperator();
    cout << theoperator << setw(4) << operand2 << endl;
    cout << setw(5) << "-----" << endl;
}

int MathOperations::collectUserAnswer() const
{
    //calling print statement to display question
    print();
    int studentanswer;
    bool teller = true;
    
    //this while loop uses a boolean variable to verify whether the user answer is correct or not
    while (teller)
    {
        cout << "Please type your answer: " << endl;
        cin >> studentanswer;

        //this part forces the while loop to run until a valid answer is put in
        if (cin.fail())
        {
            cin.clear();
            cout << "Invalid! Please try again..." << endl;
        }
        else
        {
            teller = false;
        }
        cin.ignore(256, '\n');
    }

    //returning student answer to main function
    return studentanswer;
}
