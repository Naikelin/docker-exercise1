#include <stdio.h>
#include <string.h>

unsigned int ELFHash(char* str, unsigned int len)
{
   unsigned int hash = 0;
   unsigned int x    = 0;
   unsigned int i    = 0;

   for(i = 0; i < len; str++, i++)
   {
      hash = (hash << 4) + (*str);
      if((x = hash & 0xF0000000L) != 0)
      {
         hash ^= (x >> 24);
      }
      hash &= ~x;
   }

   return hash;
}

int main(int argc, char** argv)
{

    int v1 = ELFHash(argv[1], strlen(argv[1]));

    if (79012290 == v1) printf("%s\n", "bWUgZWNoZSByZWRlcyBVd1UK");
    else printf("incorrect %s\n", argv[1]);
    
    return 0;
}