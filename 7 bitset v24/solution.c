#include <stdint.h>  // (u)int{8,16,32,64}_t
#include <stdbool.h> // bool, true, false
#include <stdio.h>   // getchar, printf

// Есть ли слово, все согласные которого глухие?
typedef uint32_t bitset;
const bitset voiceless = ((1 << ('k' - 'a')) | (1 << ('p' - 'a')) | (1 << ('s' - 'a')) | (1 << ('t' - 'a')) | (1 << ('f' - 'a')) | (1 << ('h' - 'a')));

int main(void)
{
   bitset word = 0;
   char c;
   uint32_t counter = 0;

   while ((c = getchar()) != '\n')
   {
      if (c == ' ') // пустота
      {
         word = 0;
      }
      else if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u' && c != 'y') // все согласные
      {
         word = word | (1u << (c - 'a'));
      }

      if (word != 0)
      {
         if (((word & voiceless) == word))
         {
            counter = counter + 1;
         }
         else
         {
            counter = 0;
         }
      }
   }
   if (counter > 0)
   {
      printf("YES\n");
   }
   else
   {
      printf("NO\n");
   }
}
