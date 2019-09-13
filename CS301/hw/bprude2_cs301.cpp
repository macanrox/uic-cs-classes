#include <iostream>
#include <string.h>
#include <stdio.h>
#include <conio.h>
using namespace std;

// RE parser
//
// Bresia Prudente, bprude2
// U. of Illinois, Chicago
// CS301, Spring 2013: HW8-PE
//
//GRAMMAR GOES HERE:
//  <RE>       -> <C> <RE_REST>
//  <RE_REST>  -> '|' <C> <RE_REST> | $
//  <C>        -> <K> <C> | $
//  <K>        -> <Elem> <K_REST>
//  <K_REST>   -> '*' <K_REST> | $
//  <E>        -> 'a'|'b'|'c'|'d'| '(' <RE> ')'

//Declare global variables
string input;
int index;
void RE();
void RE_REST();
void C();
void K();
void K_REST();
void E();

//FUNCTIONS//
int nextChar()
{
    return input[index];
}//end int nextChar

void consume()
{
    index++;
}//end void consume

void match(int c)
{
    if(c == nextChar())
        consume();
}//end void match

void RE()
{
    C();
    RE_REST();
}//end void RE

void RE_REST()
{
    if(nextChar() == '|')
    {
        match('|');
        C();
        RE_REST();
    }
    else
        ;
}//end void RE_REST

void C()
{
    K();
    C();
       ;
}//end void C

void K()
{
    E();
    K_REST();
}//end void K

void K_REST()
{
    if(nextChar() == '*')
    {
        match('*');
        K_REST();
    }
    else
        ;
}//end void K_REST

void E()
{
    if(nextChar() == 'a')
    {
        match('a');
    }
    else if(nextChar() == 'b')
    {
        match('b');
    }
    else if(nextChar() == 'c')
    {
        match('c');
    }
    else if(nextChar() == 'd')
    {
        match('d');
    }
    else if(nextChar() == '(')
    {
        match('(');
        RE();
        if(nextChar() == ')')
        {
            match(')');
        }//end if
    }//end else if
}//end E

int main()
{
    cout << "Enter a regular expression: ";
    getline(cin, input);
    
    input = input + "$";
    
    try
    {
        RE();
        match('$');
        
        cout << endl;
        cout << "This regular expression is valid." << endl;
        cout << endl;
    }//end try
    
    catch(...)
    {
        cout << endl;
        cout << "This regular expression is invalid." << endl;
        cout << endl;
    }//end catch
    
    getch();
    exit(0);
}//end main
