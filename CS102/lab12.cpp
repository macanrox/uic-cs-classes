/*
 * Author: Yaohua Li
 * Date:   04/03/2012
 * */

#include <iostream>
#include <string>
using namespace std;

const int InputLengthSize = 80;

int CountAndPrint(char *c)
{
    // declare
    char fullText [ 80 ];
    int spacePosition;
    int length = strlen (c);
    
    // create space for a copy
	char stringCopy[ InputLengthSize ];
	
	// pull out word
	spacePosition = strchr ( c, ' ') - c;
	
	//copy a substring
	strncpy( fullText, c, spacePosition);	
	
    // write out null character to terminate string
    fullText [ spacePosition ] = '\0';
	cout << fullText << endl;
	
	for (int i = 0; i < strlen(c); i++)
	{
           
            strcpy( fullText, ( strchr( c, ' ') + 1 ) );
        	strcpy( c, fullText);
        	
            spacePosition = strchr ( c, ' ') - c;
        	strncpy( fullText, c, spacePosition);
 
            fullText [ spacePosition ] = '\0';
            cout << fullText << endl;    
            
     }
        
	
	system("pause");
    return 0;
} // end CountAndPrint

int main() 
{
	// write your (and your partner's) name and netid in below
	cout << "Author: Bresia Prudente bprude2" << endl;

	char str[80];
	cin.getline(str, 80);
	cout << "You entered: " << str << endl;
	cout << "Those words individually are:" << endl;
    int count = CountAndPrint(str);
	cout << "There were " << count << " words" << endl;
}
