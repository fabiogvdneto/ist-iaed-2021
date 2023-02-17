#include <stdio.h>

int main()
{
	int month_days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int d, m, y;

	scanf("%d-%d-%d", &d, &m, &y);

	if (d == month_days[m - 1])
	{
		d = 1;
		
		if (m == 12)
		{
			m = 1;
			y++;
		}
		else m++;
	}
	else d++;

	printf("%02d-%02d-%04d", d, m, y);

	return 0;
}
