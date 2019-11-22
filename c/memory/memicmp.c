#include <stdio.h>
//#include <memory.h>

/*
 * memicpm (a,b,i); a ==  b return 0
 *		    a  >  b return -1
 *		    a  <  b return 1
 */
int memicmp( void *, void *, int);
int main()
{
	char a[] = "abcdefg";
	char b[] = "abcdefg";
	int c = memicmp(a, b, 7);
	printf("%d", c);
	return 0;

}


int memicmp(void *a, void *b, int c)
{

	if (a == NULL || b == NULL)
		return 0;
	if (c == 0)
		return 0;
	
	char *str1 = a;
	char *str2 = b;
	char * last = str1 + c;

	for (; (*str1 == *str2) && str1 <= last; str1 ++, str2 ++);
	if (*str1 == *str2)
		return 0;
	else
		if (*str1 > *str2)
			return -1;
		else if (*str1 < *str2)
			return 1;
}
