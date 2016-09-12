#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

double getRandomNumber_y(const double x, const double y);
double getRandomNumber_x(const double x, const double y);
bool isInsideCircle1(const double x, const double y);
bool isInsideCircle2(const double x, const double y);
bool isInsideSquare(const double x, const double y);

void main()
{
	FILE *of = fopen("dumbbell.txt", "w");
	srand((unsigned int)time(NULL));

	for (int i = 0; i < 10000; i++)
	{
		double x = getRandomNumber_x(0.0, 3.0);
		double y = getRandomNumber_y(0.0, 1.0);

		if (isInsideCircle1(x, y) || isInsideCircle2(x, y) || isInsideSquare(x, y) == true)
		{
			fprintf(of, "%f %f\n", x, y);
		}

	}
	fclose(of);
}

double getRandomNumber_y(const double min, const double max)
{
	double temp = (double)rand() / (double)RAND_MAX;

	temp = min + (max - min)*temp;
	return temp;
}
double getRandomNumber_x(const double min, const double max)
{
	double temp = (double)rand() / (double)RAND_MAX;
	temp = max - (max - min)*temp;
	return temp;
}
bool isInsideCircle1(const double x, const double y)
{
	const double x_c = 0.5;
	const double y_c = 0.5;
	const double r = 0.5;
	const double f = (x - x_c)*(x - x_c) + (y - y_c)*(y - y_c) - r*r;

	if (f > 0.0)
		return false;
	else
		return true;
}
bool isInsideCircle2(const double x, const double y)
{
	const double x_c = 2.5;
	const double y_c = 0.5;
	const double r = 0.5;
	const double f = (x - x_c)*(x - x_c) + (y - y_c)*(y - y_c) - r*r;

	if (f > 0.0)
		return false;
	else
		return true;
}
bool isInsideSquare(const double x, const double y)
{
	if (x >= 1.0&&x <= 2.0&&y >= 0.3&&y <= 0.6)
	{
		return true;
	}
	else
		return false;
}