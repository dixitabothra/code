#include<stdio.h>
#include<string.h>


void swap(char * a, char * b)
{
	char temp;
    	temp = *a;
    	*a = *b;
    	*b = temp;
}


void perm(char * input, int l, int r)
{
	int i; 
	if (l == r)
		printf("%s\n",input);
	else
	{
		printf
			("INPUT ---------%s\n", input);
		for( i = l; i<=r; i++)
		{
			swap(input+l,input+i);
			perm(input, l+1, r);
			swap(input+l, input+i);
		}
	}
	
}



int main(int argc, char ** argv)
{
	perm(argv[1], 0 , strlen(argv[1])-1);
}
