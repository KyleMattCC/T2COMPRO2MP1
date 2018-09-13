/*
    FIlename: compare.c
    Author: Florante R. Salvador
    Description: compare model with log file
    Last Update: Feb. 27, 2011
*/


#include <stdio.h>
#include <string.h>


typedef char Str60[61];

int main(int argc, char *argv[])
{
    FILE *fp_model;
    FILE *fp_log;

    int count_model;
    int count_log; 
    int diff;

    //int count;

    Str60 strModel;
    Str60 strLog;   
    int read_model; 
    int read_log; 


//    printf("arg1 %s\n", argv[1]);
//    printf("arg2 %s\n", argv[2]);

   
    fp_model = fopen(argv[1], "r");
    fp_log   = fopen(argv[2], "r");

    diff =  0;
    count_model = 0;
    count_log = 0;


    read_model = fscanf(fp_model, "%s", strModel);
    read_log   = fscanf(fp_log, "%s", strLog);

    while (read_model == 1) {
       count_model++;       count_log++;



       // printf("count = %d, str = %s\n", count, strModel);       
       //printf("%3d %s\n", count_model, strModel);
       //printf("%3d %s\n", count_log, strLog);

              

       if ( strcmp(strModel, strLog) == 0 )
       {

          printf("%s %s %3d SAME\n", strModel, strLog, count_model);
       }
       else {
          printf("%s %s %3d DIFF\n", strModel, strLog, count_model);
          diff++;
       }
        
       read_model = fscanf(fp_model, "%s", strModel);               
       read_log = fscanf(fp_log, "%s", strLog);

       if (read_model == 1 && read_log == -1) {
          // printf("INCOMPLETE LOG FILE!\n");
                   
          // break;
          strcpy(strLog, "INCOMPLETE\n");

       }
    } 


    fclose(fp_model);
    fclose(fp_log);

    printf("count_model = %d\n", count_model);
    printf("count_log   = %d\n", count_log); 
    printf("diff        = %d\n", diff);
    if (diff)
       printf("*** With DIFFERENCE ***\n");
    return 0;
}





