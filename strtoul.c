
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	unsigned long int  id ;
	char **endptr = NULL;
	
	char str[] = "hello";
	char str2[] = "jiapan";
	char str3[100] = {0};
	snprintf(str3,100,"%s%s",str,str2);
	printf("%s\n",str3);
	
	id = strtoul(str3,endptr,0)
	if(id)
	{
		printf("there is some num in string\n");
	}
	else
	{
		printf("there is no num in string\n");
		printf("%s\n",*endptr);
	}
	
	return 0;
}