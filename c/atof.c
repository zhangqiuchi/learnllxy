#include <stdio.h>

double atof(char *);

int main()
{
	char a[] = "155.35";
	double b = atof(a);
	printf("%lf", b);
	getchar();
	return 0;

}
double atof(char *str)
{
	char *istr = str;
	double db = 0.0;
	float cheng = 1.0;
	float xiaoshu = 1.0;
	if (str == NULL)
	{
		return db;
	}
	while (*istr != '\0')
	{
		if ((*istr >'9'|| *istr <'0') && *istr != '-' && *istr != '+' && *istr != '.' )
			return db;
		istr ++;
	
	}
	if (*str == '-')
	{
		cheng *= -1;
		str ++;
	}
	else if (*str == '+')
	{
		str ++;
	}
	for (;*str != '.'; str ++)
	
		db = db * 10.0 + (*str - '0');
	
	str ++;
	for (;*str != '\0'; str ++)
	{
		xiaoshu /= 10;
		db += xiaoshu * (*str - '0');

	}

	db *= cheng;
	return db;
}
