#include <stdio.h>
#include <stdlib.h>

void bubble_a(int *data, int count)
{
        int i, last;

        for(last = count-1; last > 0; last--)
        {
                for(i = 0; i < last; i++)
                {
			/* We can evalute x[i] as *(x+i) */
                        if(*(data+i+1) < *(data+i))
                        {

                                /* Swap adjacent elements */
                                int t = *(data+i+1);
                                data[i+1] = *(data+i);
                                *(data+i) = t;

                        }//end if

                }//end for

        }//end for

}//end void bubble_a

int main()
{

        /* Test the array by adding some elements */
	int arr[5] = {3, 8, 1, 2, 4};

        bubble_a(arr, 5);
	int x;

	/* This will print each element of the array */
        for(x = 0; x < 5; x++)
        {

		printf("%d\n", arr[x]);

	}//end for
	return 0;

}//end main 
