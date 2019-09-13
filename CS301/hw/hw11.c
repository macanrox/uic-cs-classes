#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//We use a compare function for qsort
int compare(const void *a, const void * b)
{
	return ((*(char *)a) - (*(char *)b));
}//end int compare

//Swap a and b
void swap(char * a, char * b)
{
    char t = *a;
    *a = *b;
    *b = t;
}//end void swap

// This function finds the index of the smallest character
// which is greater than 'first' and is present in str[l..h]
int findSmall[], char first, int l, int h)
{
    // initialize index of ceiling element
    int index = l;
    int i;

    // Now iterate through rest of the elements and find
    // the smallest character greater than 'first'
    for(i=(l+1); i<=h; i++)
    {
      if((str[i] > first) && (str[i] < str[index]))
            index = i;
	}//end for

    return index;
}//end findSmall

// Print all permutations of str in sorted order
void sortPerm(char str[])
{
    // Get size of string
    int size = strlen(str);

    // Sort the string in increasing order
    qsort(str, size, sizeof( str[0] ), compare);

    // Print permutations one by one
    bool isFinished = false;
    while(!isFinished)
    {
        // print this permutation
        printf("%s \n", str);

        // Find the rightmost character which is smaller than its next
        // character. Let us call it 'first char'
        int i;
        for(i=(size - 2); i>=0; --i)
        {
           if (str[i] < str[i+1])
              break;
		}//end for(i=...

        // If there is no such chracter, all are sorted in decreasing order,
        // means we just printed the last permutation and we are done.
        if(i == -1)
            isFinished = true;
        else
        {
            // Find the ceil of 'first char' in right of first character.
            // Ceil of a character is the smallest character greater than it
            int index = findSmall(str, str[i], i + 1, size - 1);

            // Swap first and second characters
            swap(&str[i], &str[index]);

            // Sort the string on right of 'first char'
            qsort(str + i + 1, size - i - 1, sizeof(str[0]), compare);
        }
    }
}//end void sortPerm