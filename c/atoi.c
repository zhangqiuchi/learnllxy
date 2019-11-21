#include <stdio.h>
#include <string.h>
//#include <stdlib.h>

int atoi(char *);
char * itoa(int, char *, int);


int main(void)
{
    char a[] = "1234507890";
    int c = 123456;
    char d[] = {0};
    int b = atoi(a);
    itoa(c, d, 10);
    printf("%d %s", b, d);
	getchar();
    return 0;
}

#if 1
int atoi(char * str)
{
	char * istr = str;
	
	while (*istr != '\0')
	{
		if (*istr <= '0' && *istr >= '9')
			return 0;
		istr ++;
	}
	int lastnum = 0;
	
	for (int i =0; i < strlen(str); i ++)
	{
		lastnum *= 10;
		lastnum += str[i] - '0';
	}
	
	return lastnum;
}
char * itoa(int value, char * string, int redix)
{
	int wei = 0;
	int c = value;
	if (string == NULL)
		return NULL;
	for (;c;c /= redix)
		wei ++;
	printf("%d", wei);
	for (int i = wei-1; i >= 0; i --)
	{
		string[i] = value%redix+48;
		value /= redix;
	}
	string[wei] = '\0';
	return string;
}
#endif
