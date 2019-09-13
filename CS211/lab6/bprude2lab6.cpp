			/*
			printf( "Congratulations! You won!\n"
					"It took you [this many] guesses." );
			exit(-1);
		*/

for (p = 0; p < CODELENGTH; p++)
{
    printf("%d", guess[p]);

    if (code[p] == guess[p])
    {
    	match++;
    }
    if ((code[p]!= guess[p]) &&
    	((code[p] == guess[p+1]) ||
    	(code[p] == guess[p+2]) ||
    	code[p] == guess[p+3]) ||
    	code[p] == guess[p-1]) ||
    	(code[p] == guess[p-2]) ||
    	(code[p] == guess[p-3]) ))
    {
   		nearMatch++;
    }

}