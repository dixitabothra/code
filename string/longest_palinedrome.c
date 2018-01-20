#include<stdio.h>
#include<string.h>


void palindrome(char* input, int n)
{
	char aux_arr[2*n +1];
	int pal_len[2*n+1];
	int i,j=0;
	int max = -1 ;
	int index = -1;
	
	memset(aux_arr,'#',sizeof(aux_arr));
	memset(pal_len,-1,sizeof(pal_len));

	for(i =1; i < 2*n +1; i = i+2,j++)
	{
		aux_arr[i] = input[j];
	}
	

	for(i = 1; i < 2*n +1; i++)
	{
		for(j = 0; j <= i; j = j+1 )
		{
			if(aux_arr[i+j]== aux_arr[i-j] )
			{
				pal_len[i]++;
			}
			else
				break;
		}
		if(max < pal_len[i])
		{
			max =  pal_len[i]  ;
			index = (i+1)/2;
			 printf("max %d  index %d\n", max, index);
		}


	}
	for(i=0; i<max;i++ )
	{
		printf("%c",input[index-((max+1)/2) +i]);
	}
	printf("\n---max %d  index %d\n", max, index);



}	
int main(int argc, char** argv)
{
	palindrome(argv[1], strlen(argv[1]));
}
