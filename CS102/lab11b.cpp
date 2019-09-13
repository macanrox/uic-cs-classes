/*
Author: Bresia Prudente 
netID: bprude2
Lab: Wednesday 11-11:50

Basic Calculator
*/

#include <iostream>
using namespace std;

// declare functions
int add (int x, int y);
int subtract (int x, int y);
int multiply (int x, int y);
int divide (int x, int y);

int main()
{
    int firstNumber, secondNumber;
    char operand;
    int result;

    cout << "Welcome to the calculator \n\n";
    
    cout << "Enter the first number: ";
    cin >> firstNumber;
        
    cout << "Enter an operand (+, -, * or /): ";
    cin >> operand;

    cout << "Enter the second number: ";
    cin >> secondNumber;

    cout << "You entered " << firstNumber << "," << operand << "," << secondNumber << endl;


    if (operand == '+')
    {
       int result;
       string result2;
       result = add (firstNumber, secondNumber);
       result2 = result;
    }
    else if (operand == '-')
    {
         int result;
         string result2;
         result = subtract (firstNumber, secondNumber);
         result2 = result;
    }
     else if (operand == '*')
    {
          int result;
          string result2;
          result = multiply (firstNumber, secondNumber);
          result2 = result;
    }
    else if (operand == '/')
    {
         int result;
         string result2;
         result = divide (firstNumber, secondNumber);
         result2 = result;
    }

    cout << "Exiting program... \n" << endl;


    system("pause");
}   // end main


int add (int x, int y)
{    
    cout << "The result of " << x << " + " << y << " is " <<x + y << "\n" << endl;
}   // end add


int subtract (int x, int y)
{    
    cout << "The difference of " << x << " - " << y << " is " << x - y << "\n" << endl;
}   // end subtract


int multiply (int x, int y)
{    
    cout << "The product of " << x << " * " << y << " is " << x * y << "\n" << endl;
}   // end multiply


int divide (int x, int y)
{    
    cout << "The result of " << x << " / " << y << " is " << x / y << "\n" << endl;
}   // end divide
