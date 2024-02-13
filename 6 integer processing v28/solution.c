// Получить двоично кодированное десятичное представление числа.
#include <stdint.h>  // (u)int{8,16,32,64}_t
#include <stdbool.h> // bool, true, false
#include <stdio.h>   // printf, scanf

int main(void)
{
   int64_t number;
   int64_t number_lenght = 0;
   int64_t temp_number;
   int64_t left_number_digit;

   printf("Decimal number: ");
   // scanf("%ld", &number); // проверка scanf == 1
   //  printf("%ld", number);
   if (scanf("%ld", &number) != 1)
   {
      printf("ERROR");
      return 1;
   }

   if (number < 0) // если отрицательное число
   {
      number *= -1;
   }

   temp_number = number;

   if (number == 0)
   {
      number_lenght = 1;
   }
   else
   {
      while (temp_number > 0)
      {
         number_lenght++; // вычисляем длину
         temp_number = temp_number / 10;
      }
   }

   printf("Binary Coded Decimal: ");
   while (number_lenght > 0)
   {
      temp_number = number;
      for (int8_t i = 0; i < number_lenght - 1; i++) // берем по цифре слева
      {
         temp_number = temp_number / 10;
      }
      left_number_digit = temp_number % 10;

      for (int8_t i = 8; i >= 1; i = i / 2) // двоичное число в 4 битах
      {
         printf("%ld", left_number_digit / i);
         left_number_digit = left_number_digit % i;
      }
      printf(" ");
      number_lenght--;
   }
   return 0;
}
