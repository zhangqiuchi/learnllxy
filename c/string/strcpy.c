#include <stdio.h>
#include <string.h>
#include <malloc.h>

int main()
{
	char a[] = "zhangzhangzhang’≈";
	char *b = alloca(sizeof(char) * 1024);
	strcpy(b, a);
	printf("%s", b);
	return 0;
}
