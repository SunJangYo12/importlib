/*
gcc main.c importlib.c -ldl
*/

#include <stdio.h>
#include "importlib.h"

int main()
{
   if (importLibInit() == 1) {
       printf("success open library\n");
       printf("%d\n", jumlah(10, 30));
       importLibDeinit();
   }
}
