#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef char Str30[31];

#define LIST_SIZE 154459

struct listTag{
	Str30 element;
	struct listTag *pNext;
};

/*void lowerWord(char c){
	 int i;
	 
	 for(i=0; word[i]!= '\0'; i++){
		      printf("%c", word[i]);
     }		 		  									 		  
}*/

int getHash(Str30 word){
	int i;
	int hashAdd =0;

  	for (i =0; word[i]!='\0'; i++)
    		hashAdd = (hashAdd * 10 + word[i]) % LIST_SIZE;
	 
  	return hashAdd;
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
		      //printf("%d ", hashAdd);
		      if(!(strcmp((universe+hashAdd)->element, "-1"))){
					strcpy((universe+hashAdd)->element, word);
					//printf("normal %s\n", (universe+hashAdd)->element);
					}
					
			  else if((universe+hashAdd)->pNext){
			  	    pTemp = (universe+hashAdd)->pNext;
			  	    while(pTemp->pNext)
  	    						pTemp = pTemp->pNext;
					pTemp->pNext = malloc(sizeof(struct listTag));
					pTemp->pNext->pNext = NULL;
					strcpy(pTemp->pNext->element, word);
					//printf("continue chain %s\n", word);
					}
							
			  else{
			  	  	(universe+hashAdd)->pNext = malloc(sizeof(struct listTag));
					(universe+hashAdd)->pNext->pNext = NULL;
       				strcpy((universe+hashAdd)->pNext->element,word); 
					//printf("new chain %s\n", word);     		
		         	}
     }	
}

void Search(struct listTag *universe, Str30 word)
{
   int i;
   int quesNum=0, astNum=0;
   struct listTag *pTemp;

   pTemp = NULL;

   for(i=0; word[i] != '\0'; i++){
	if(word[i]=='?')
		quesNum++;	
	else if(word[i]=='*')
		astNum++;
   }

   if(quesNum == 0 && astNum == 0){
	if(!(strcmp((universe+getHash(word))->element, word)))
		printf("%s\n", word);
	else if((universe+getHash(word))->pNext != NULL){
		pTemp = (universe+getHash(word))->pNext;
		while(pTemp != NULL){
					if(!(strcmp(pTemp->element,word))){
		   			     printf("%s\n", word);
		   			     break;
				    }
				    
				    else
				    	 pTemp = pTemp->pNext;
	    }
	    if(pTemp == NULL)
	    		 printf("NOMATCH\n");	    
		}
		    	 
    else
	 	 printf("NOMATCH\n");
    }  
}


		 
int main()
{
 	struct listTag *universe; 
 	
 	universe = malloc(sizeof(struct listTag)*LIST_SIZE);
 	
 	Initialize(universe); 	
 	Search(universe, "computer");
 	Search(universe, "CoMpUTEr");
 	
 	free(universe);
 	return 0;
}
