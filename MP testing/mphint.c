#include<stdio.h>

int main()
{
   int i, retval;
   int x, y, z;

   for(i = 0; i<3; i++){
   	retval = scanf("%d %d %d", &x, &y, &z);
   	printf("retval = %d, x = %d, y = %d, z = %d\n", retval, x, y, z);
   }

   return 0;
}