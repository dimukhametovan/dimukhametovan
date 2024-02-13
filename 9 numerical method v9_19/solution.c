#include <stdint.h> // (u)int{8,16,32,64}_t
#include <stdbool.h> // bool, true, false
#include <float.h>	 // (FLT|DBL)_EPSILON
#include <stdio.h>	 // scanf(), printf()
#include <math.h>	 // M_PI, sin(), cos(), log(), pow(), ...
/*вариант 9 + 19
2 функции
методы: итераций*/
// комментарий
/* изначальные функции

double func_9(double x)
{
	return x * x - log(1 + x) - 3;
}

double func_19(double x)
{
	return x - (1 / (3 + sin(3.6 * x)));
}

*/

double phi_func_9(double x)
{
	return sqrt(log(1 + x) + 3);
}

double phi_func_19(double x)
{
	return 1 / (3 + sin(3.6 * x));
}

void iteration_method(int8_t a, double (*phi_func)(double))
{
	const double eps = DBL_EPSILON;
	double x0 = a;
	double x1 = phi_func(x0);
	int64_t iter = 0;

	while (fabs(x1 - x0) > eps)
	{
		x0 = x1;
		x1 = phi_func(x0);
		iter++;
		printf("iter = %ld | xk = %f \n", iter, x1);
	}
	printf("final result = %f \n", x1);
}

int main(void)
{
	const int8_t a_9 = 2, a_19 = 0;
	int8_t func;
	printf("Выберите функцию: 1 или 2 \n");

	if (scanf("%hhd", &func) != 1)
	{
		printf("ERROR \n");
		return 1;
	}
	else
	{
		if (func == 1)
		{
			iteration_method(a_9, phi_func_9);
		}
		else if (func == 2)
		{
			iteration_method(a_19, phi_func_19);
		}
		else
		{
			printf("ERROR \n");
			return 1;
		}
	}
}
