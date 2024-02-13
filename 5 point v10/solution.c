#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct point
{
   int x, y;
};

bool point_intersects(struct point p); // сигнатура
// Write your necessary constants and functions here
int sign(int a)
{
   if (a > 0)
   {
      return 1;
   }
   else if (a == 0)
   {
      return 0;
   }
   else
   {
      return -1;
   }
}

int max(int a, int b)
{
   if (a > b)
   {
      return a;
   }
   else
   {
      return b;
   }
}

int min(int a, int b)
{
   if (a < b)
   {
      return a;
   }
   else
   {
      return b;
   }
}

int min3(int x, int y, int z)
{
   if (x <= y && x <= z)
   {
      return x;
   }
   else if (y <= x && y <= z)
   {
      return y;
   }
   else
   {
      return z;
   }
}

int abs(int a)
{
   if (a >= 0)
   {
      return a;
   }
   else
   {
      return ((-1) * a);
   }
}

int mod(int a, int b)
{
   return (a % b + b) % b;
}

int main(void)
{
   int l = 0;
   int l_old = 0;
   bool is_hited_flag = false;
   int step = 1;
   struct point p;
   struct point p_old;

   printf("i0 = ");
   scanf("%d", &p.x);
   printf("j0 = ");
   scanf("%d", &p.y);
   printf("l0 = ");
   scanf("%d", &l);

   // system("chcp 1251");
   // setlocale(LC_ALL, "Rus");
   while ((step < 50) && (is_hited_flag == false))
   {

      p_old.x = mod((p.x + step) * (p.y - step) * (l + step), 25);
      p_old.y = mod(min(p.x + step, max(p.y - step, l - step)), 30);
      l_old = abs(p.y - step) * sign(p.x) - abs(p.x - l) * sign(p.y);
      step = step + 1;
      is_hited_flag = point_intersects(p_old);
      p = p_old;
      l = l_old;
   }

   if (is_hited_flag == true)
   {
      printf("i = %d, j = %d, l = %d, step = %d \n", p.x, p.y, l, step);
      printf("The point fell into the specified region of the plane in no more than 50 steps in %d iterations \n", step);
   }
   else
   {
      printf("i = %d, j = %d, l = %d, step = %d \n", p.x, p.y, l, step);
      printf("The point did not fall within the specified area \n");
   }
}

bool point_intersects(struct point p)
{
   // Write your point intersection check here
   if ((p.x >= 5 && p.x <= 15 && p.y <= -5 && p.y >= -15))
   {
      return true;
   }
   else
   {
      return false;
   }
}