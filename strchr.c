#include<stdio.h>
#include<string.h>
//#if not define
char * strchr(const char *,int);
int main()
{
char * str = NULL;
char c = '\\';
const char wc[] = "/sdhgu /gdfhg /hud u/r ing";
str = strchr(wc, c);
if(str)
{
	printf("%s\n",str);
}
else
{
	printf("not find\n");
}

return 0;
}
