#include <stdio.h>

typedef struct
{
	int y, m, d;
}
Date;

int main()
{
	Date date1, date2;
	int i1, i2;

	scanf("%d-%d-%d%d-%d-%d", &date1.d, &date1.m, &date1.y, &date2.d, &date2.m, &date2.y);

	i1 = date1.y * 10000 + date1.m * 100 + date1.d;
	i2 = date2.y * 10000 + date2.m * 100 + date2.d;

	if (i1 > i2)
	{
		Date temp = date1;
		date1 = date2;
		date2 = temp;
	}

	printf("%02d-%02d-%04d\n%02d-%02d-%04d\n", date1.d, date1.m, date1.y, date2.d, date2.m, date2.y);

	return 0;
}
