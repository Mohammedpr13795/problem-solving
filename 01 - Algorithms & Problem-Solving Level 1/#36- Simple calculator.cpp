#include <iostream>
using namespace std;

enum enOperationType { Add = '+', Subtract = '-', Multiply = '*', Divide = '/' };

float ReadNumber(string Message)
{
    float Number = 0;
    cout << Message << endl;
    cin >> Number;
    return Number;
}

enOperationType ReadOpType()
{
    char OT = '+';

    cout << "Please enter the OperationType ( + , - , * , / ):\n";
    cin >> OT;
    return (enOperationType)OT;
}

float Calculate(float Num1, float Num2, enOperationType Operator)
{
    switch (Operator)
    {
    case enOperationType::Add:
        return Num1 + Num2;
    case enOperationType::Subtract:
        return Num1 - Num2;
    case enOperationType::Multiply:
        return Num1 * Num2;
    case enOperationType::Divide:
        return Num1 / Num2;
    default:
        Num1 + Num2;
    }
}

int main()
{



    float Number1 = ReadNumber("Please enter the first number:\n");
    float Number2 = ReadNumber("Please enter the second number:\n");

    enOperationType Operator = ReadOpType();

    cout << endl << "Result = " << Calculate(Number1, Number2, Operator);

    return 0;
}

Problem 36- Simple calculator (2)

#include <iostream>

using namespace std;


struct stEqualation {
    float number1 = 0;
    char OpType;
    float number2 = 0;
};


stEqualation ReadEqualation()
{
    stEqualation Equalation;


    cout << "Please enter the first number: \n";
    cin >> Equalation.number1;

    cout << "Please enter the OperationType: ( + , - , * , / ):\n";

    cin >> Equalation.OpType;

    cout << "Please enter the second number: \n";
    cin >> Equalation.number2;

    return Equalation;
}

void Calculate(stEqualation Equalation)
{


    switch (Equalation.OpType)
    {
    case '+':
        cout << Equalation.number1 << " + " << Equalation.number2 << " = " << Equalation.number1 + Equalation.number2;
        break;
    case '-':
        cout << Equalation.number1 << " - " << Equalation.number2 << " = " << Equalation.number1 - Equalation.number2;
        break;
    case '*':
        cout << Equalation.number1 << " * " << Equalation.number2 << " = " << Equalation.number1 * Equalation.number2;
        break;
    case '/':
        cout << Equalation.number1 << " / " << Equalation.number2 << " = " << Equalation.number1 / Equalation.number2;
        break;
    default:
        cout << "Wrong operation.";
    }
}


int main()
{
    Calculate(ReadEqualation());


    return 0;

}



