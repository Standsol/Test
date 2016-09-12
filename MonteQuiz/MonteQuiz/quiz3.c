#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

double getRandomNumber(const double x, const double y);
bool isInsideEllipse(const double x, const double y);

void main()
{
	FILE *of = fopen("ellipse.txt", "w");
	srand((unsigned int)time(NULL));

	for (int i = 0; i < 10000; i++)
	{
		double x = getRandomNumber(0.0, 1.0);
		double y = getRandomNumber(0.0, 1.0);

		if (isInsideEllipse(x, y)==true)
		{
			fprintf(of, "%f %f\n", x, y);
		}

	}
	fclose(of);
}

double getRandomNumber(const double min, const double max)
{
	double temp = (double)rand() / (double)RAND_MAX;

	temp = min + (max - min)*temp;
	return temp;
}
bool isInsideEllipse(const double x, const double y)
{
	const double a = 0.5;
	const double b = 0.3;
	const double f = (x*x / a*a) + (y*y / b*b);

	if (f == 1.0)
		return true;
	else
		return false;
}
