#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef char Str30[31];

#define LIST_SIZE 154459

struct listTag{
   Str30 element;
   struct listTag *pNext;
};

int getHash(Str30 word){
   int i;
   int hashAdd =0;

   for (i =0; word[i]!='\0'; i++)
		hashAdd = (hashAdd * 10 + word[i]) % LIST_SIZE;
	 
   return hashAdd;
}

void Traverse(struct listTag *pCurrent){
   int ctr = 0;
   if(pCurrent != NULL){
	while(pCurrent){
        printf("%s\n", pCurrent->element);
		ctr++;
        pCurrent = pCurrent->pNext;
    }
   }

   else
	printf("NOMATCH\n");

    printf("%d\n", ctr);

}

struct listTag *Create_Sort_Node(struct listTag *pList, Str30 word){
   struct listTag *pTemp;
   struct listTag *pTrail;
   struct listTag *pCurrent;

   pTrail = NULL;
   pCurrent = pList;

   pTemp = malloc(sizeof(struct listTag));
   strcpy(pTemp->element, word);
   pTemp->pNext = NULL; 

   if(pList == NULL)
	pList = pTemp;

   else{
	while(pCurrent != NULL){
		if(strcmp(pTemp->element, pCurrent->element) == 1){
			pTrail = pCurrent;
			pCurrent = pCurrent->pNext;
		}
		
		else
			break;
	}
   if(pTrail != NULL){
	pTrail->pNext = pTemp;
	pTemp->pNext = pCurrent;
   }

   else{
	pTemp->pNext = pCurrent;
	pList = pTemp;
   }
   }

   return pList;
}

void Initialize(struct listTag *universe){
   int i;
   Str30 word;
   int hashAdd;
   struct listTag *pTemp;    
  
   for(i=0; i<LIST_SIZE; i++){
		strcpy((universe+i)->element, "-1");
		(universe+i)->pNext = NULL;
   }
     
   while(scanf("%s", word) == 1){
   hashAdd = getHash(word);
   
   if(!(strcmp((universe+hashAdd)->element, "-1"))){
		strcpy((universe+hashAdd)->element, word);
	}
					
   else if((universe+hashAdd)->pNext != NULL){
		pTemp = (universe+hashAdd)->pNext;
		while(pTemp->pNext)
			pTemp = pTemp->pNext;
			
		pTemp->pNext = malloc(sizeof(struct listTag));
		pTemp->pNext->pNext = NULL;
		strcpy(pTemp->pNext->element, word);	
	}
	
	else{
		(universe+hashAdd)->pNext = malloc(sizeof(struct listTag));
		(universe+hashAdd)->pNext->pNext = NULL;
		strcpy((universe+hashAdd)->pNext->element,word);		
	}
   }	
}


void Search(struct listTag *universe, Str30 key)
{
   int i, j, k;
   int quesNum=0, astNum=0, astCtr;
   struct listTag *pTemp;
   struct listTag *pList;
   Str30 word = "\0";

   pList = NULL;
   pTemp = NULL;

   for(i=0; key[i] != '\0'; i++){
		if(key[i]=='?'){
			word[i] = key[i];			
			quesNum++;
		}
		
		else if(key[i]=='*'){
			word[i] = key[i];
			astNum++;
		}
    
		else
			word[i] = key[i];
   }
   
   strlwr(word);
   
   if(quesNum == 0 && astNum == 0){
		if(!(strcmp((universe+getHash(word))->element, word)))
			pList = Create_Sort_Node(pList, word);

		else if((universe+getHash(word))->pNext != NULL){
			pTemp = (universe+getHash(word))->pNext;
			while(pTemp != NULL){
				if(!(strcmp(pTemp->element,word))){
					pList = Create_Sort_Node(pList, word);
					break;
				}
				    
				else
					pTemp = pTemp->pNext;
			}	    
		}
   }
	
	else if(quesNum > 0){
		for(i=0; i<LIST_SIZE; i++){
            pTemp = (universe+i);
			if(strcmp(pTemp->element, "-1")){								
				while(pTemp != NULL){
					if(strlen(pTemp->element) == strlen(word)){	 
						for(j=0; word[j] != '\0'; j++){
							if(word[j] != '?'){
								if(word[j] != pTemp->element[j])
									break;
							}
						}
						
						if(j == strlen(word)){
							pList = Create_Sort_Node(pList, pTemp->element);
						}
					}
				pTemp = pTemp->pNext; 
				}
			}						 
		}
	}
	
	else if(astNum > 0){
	for(i=0; i<LIST_SIZE; i++){
		pTemp = (universe+i);
		if(strcmp(pTemp->element, "-1")){
			while(pTemp != NULL){
                k=0;
                j=0;
				astCtr = astNum;
				while(word[j] != '\0'){
                	if(astCtr){
                		if(word[j] != '*'){
                    		if(word[j] != pTemp->element[k])
                        		break;
                        	else{
                            	k++;
                            	j++;
                        	}
                    	}
                    
                    	else{
                        	j++;
							astCtr--;
							if(word[j] == '\0')
								k = strlen(pTemp->element);
							else if(word[j+1] != '\0'){		
								if(astCtr){
									while(pTemp->element[k] != word[j] && pTemp->element[k] != '\0')
                               			k++;
									if((strlen(pTemp->element)-k < strlen(word)-j-astCtr))
										break;
									else{
										j++;
										k++;
									}
								}
							}
						}						
					}

					else{
						if(word[j] != '\0'){
							if(word[j+1] == '\0'){
								k = strlen(pTemp->element)-1;
								if(word[j] == pTemp->element[k]){
									j++;
									k++;
								}
								else
									break;
							}
					
							else{
								k = strlen(pTemp->element) - strlen(word) + j;
								if(word[j] == pTemp->element[k]){
									j++;
									k++;
								}
								else
									break;
							}    
						}
					}
				}
				if(j == strlen(word) && k == strlen(pTemp->element)){
            		pList = Create_Sort_Node(pList, pTemp->element);
            	}		
				pTemp = pTemp->pNext;	
				}				 
		}
	}
   }
   Traverse(pList);
   free(pList);
}

int main()
{
  time_t  t0, t1; /* time_t is defined on <time.h> */
  clock_t c0, c1; /* clock_t is defined on <time.h> */


  struct listTag *universe; // provide the data type of universe
                   // the universe will contain the words from enable2k.txt 
  

  // declare your other own local variables here

  


  /*
     DO NOT remove the next two assignment operations  
     which measure start time t0, c0 
  */ 
  t0 = time(NULL);  // time() measures wallclock time
  c0 = clock();     // clock() measures CPU time


  /* initialize the universe of words */
  universe = malloc(sizeof(struct listTag) * LIST_SIZE);  
  Initialize(universe);


  /* test the Search() function */ 
  Search(universe, "coMMUTER");
  Search(universe, "canotn");   // should produce same resul t as above 
  Search(universe, "a?t");
  /*Search(universe, "a*t");
  Search(universe, "art*");
  Search(universe, "*art");
  Search(universe, "wxyz");*/    // this will not produce a match 


  /*
     DO NOT remove the remaining statements below.

     Measure end time, and report elapsed time.

     Note: the elapsed time will tell you the performance of your 
           design/implementation.  Strive for a computationally
           efficient solution.
  */

  // measure end time t1, c1 
  t1 = time(NULL);
  c1 = clock();

  printf ("\tbegin (wall):            %ld\n", (long) t0);
  printf ("\tbegin (CPU):             %d\n", (int) c0); 
  printf ("\tend (wall):              %ld\n", (long) t1);
  printf ("\tend (CPU);               %d\n", (int) c1);
  printf ("\telapsed wall clock time: %ld\n", (long) (t1 - t0));
  printf ("\telapsed CPU time:        %f\n", (float) (c1 - c0)/CLOCKS_PER_SEC);
  
  free(universe);


  return 0;


}

