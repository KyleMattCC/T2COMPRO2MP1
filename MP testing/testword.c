#include <stdio.h>
#include <string.h>

int main()
{
 	int i=0, j=1;
 	while(i<10){
				for(j=0; j<10; j++){
 		 			   if(j==5)
 		 			   break;
 		 			   else
 		 			   printf("j = %d\n", j);
					   }
					   printf("i = %d\n", i);
					   i++;}
 	
 	
 	return 0;
}
 	
