//Bubble sort
//This takes the array and its size
void bubSort(float a[], int b)
{
  int i, j;
  float temp;

  for(i=(b - 1); i>0; i--)
  {
    for(j=1; j<=i; j++)
    {
      if (a[j-1] > a[j])
      {
        temp = a[j-1];
        a[j-1] = a[j];
        a[j] = temp;
      }//end if
    }//end for(j=1...
  }//end for(i=...
}//end void

//We perform the operations here
int main(int argc, char *argv[])
{

	int i;
	float a[argc - 1];

	for(i=0; i<(argc - 1); i++)
	{
		a[i] = argv[i + 1];
	}//end for

	//Call bubble sort
	bubSort(a, (argc - 1));

	for(i=0; i<(argc - 1); i++ )
	{
		printf(" %f", a[i]);
	}//end for(i=...

	putchar();
	return 0;
}//end main