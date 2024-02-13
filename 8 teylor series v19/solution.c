#include <stdint.h>  // (u)int{8,16,32,64}_t
#include <stdbool.h> // bool, true, false
#include <float.h>   // DBL_EPSILON, FLT_EPSILON
#include <stdio.h>   // scanf(), printf()
#include <math.h>    // M_PI, ...

const int64_t MAX_ITERATIONS = 100;

// variant 19
const double A = 0.1;
const double B = 0.6;

double f_exact(double x)
{
   return cosh(x);
}

double factorial(double n)
{
   double ans = 1;
   for (int64_t i = 1; i <= n; i++)
   {
      ans *= i;
   }
   return ans;
}

double f_taylor(double x, int32_t i)
{
   // printf("%f \n", pow(x, 2 * i) / factorial(2 * i));
   return pow(x, 2 * i) / factorial(2 * i);
}

int main(void)
{
   int64_t n;
   int32_t iter = 1;
   double result_taylor = 1, k, x = 0;
   // double CONVERGENCE_EPSILON_FACTOR;

   printf("segment partition: ");
   if (scanf("%ld", &n) != 1)
   {
      printf("ERROR \n");
      return 1;
   }
   printf("precision: ");
   if (scanf("%le", &k) != 1)
   {
      printf("ERROR \n");
      return 1;
   }
   // CONVERGENCE_EPSILON_FACTOR = DBL_EPSILON;

   for (double i = 0; i < n; i += 1.0)
   {
      result_taylor = f_taylor(0, 0);
      iter = 1;
      x += fabs(A - B) / n;

      while ((fabs(f_exact(x) - result_taylor) >= DBL_EPSILON * k) && (iter <= 100))
      {
         result_taylor += f_taylor(x, iter);
         iter++;
      }
      printf("x = %lf  | n = %.2f | exact = %.12lf | taylor = %.12lf | iteration = %d \n", x, i, f_exact(x), result_taylor, iter);
   }
   return 0;
}
