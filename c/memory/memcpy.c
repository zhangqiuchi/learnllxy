#include <stdio.h>
//#include <memory.h>

void * memcpy(void *, void *, int);

int main()
{
	int a[] = {1,2,3};
	int b[3];
	memcpy(b, a, 3);
	for (int i = 0; i < 3; i ++)
		printf("%d", a[i]);
	return 0;
}


void * memcpy(void *to, void *from, int size)
{
	if (to == NULL && from == NULL)
		return NULL;
	if (size == 0)
		return NULL;
	unsigned char *to1 = (unsigned char*)to;
	unsigned char *from1 = (unsigned char*)from;

	for (;size -- > 0; to1 ++,from1 ++)
		*to1 = *from1;
	return to;
}
