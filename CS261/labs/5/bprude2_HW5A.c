      int switch_prob(int x, int n)
{
	
	int result = x;
	switch(n) 
	{
		case 0:		//do nothing
		case 1:		//left shift 
		{
			x = x << 2;		
			break;
		}//end case 1
		case 2:		//right shift
		{
			x = x >> 2;		
			break;
		}//end case 2
		case 3:		//if called by the ja instruction
		{
			x = x * 3;		//we multiply by the power of 3
			x = x * x;		//take the result and multiply by itself
			x = x + 10;		//then add 10
			break;
		}//end case 3
		case 4:		//if called by the jmp instruction
		{
			x = x * x;		//multiply the result by itself
			x = x + 10;		//then add 10
			break;
		}//end case 4
		default:
		{
			x = x + 10;		//otherwise just add 10
			break;
		}//end default
	}//end switch
	
	return result;
	
}//end switch_prob

