#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char * strtok_1(char* str, char* delim )
{
	static int start;
	static int end;
	int i = 0;
	static char * str_org;
	char * out = NULL;
        if(str != NULL)
	{
		end = strlen(str);
		start = 0;
		str_org = str;
	}
	while(start < end)
	{
		if(str_org[start] == delim[0])
			break;
		i++;
		start++;
	}
	if(i == 0)
		return NULL;
	out = malloc(i);
	memcpy(out,str_org + (start-i), i );
	out[i] = '\0';
	start ++;
	return out;
}


int main(int argc, char** argv)
{
	char *p;
	char* string = "this is string hello";
	if(argc < 3)	
	{
		printf("Usage ./a.out <sting> <delimiter>\n");
		return 0 ;
	}
	string = argv[1];
	p = strtok_1(string, argv[2]);
	
	
	while(p!=NULL)
	{	
		printf("%s\n", p);
		p = strtok_1(NULL, " ");
	}

}
