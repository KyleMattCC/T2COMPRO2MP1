# include <stdio.h>
# include <string.h>


int main ()
{
char str[30];
int ctr=0;

do{
     scanf("%s", str);
     ctr++;
     printf("%d", ctr);
}while(str);

return 0;
}
