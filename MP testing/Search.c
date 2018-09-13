void Search(struct listTag *universe, string word)
{
   int i;
   int quesNum=0, astNum=0;
   struct listTag *pTemp;

   pTemp = NULL;
   convertWord(word);

   for(i=0; i<strlen(word); i++){
	if(word[i]=='?')
		quesNum++;	
	else if(word[i]=='*')
		astNum++;
   }

   if(quesNum == 0 && astNum == 0){
	if(!(strcmp((universe+getHash(word))->element, word)))
		printf("%s\n", word);
	else if(pNext != NULL)
		pTemp = pNext;
		while(pTemp != NULL){
					if(!(strcmp(pTemp->element,word))){
		   			     printf("%s\n", word);
		   			     break;
				    }
				    
				    else
				    	 pTemp = pTemp->pNext;
	    }
		    	 
    else if(pTemp == NULL)
	 	 printf("NOMATCH\N");
    }  
}
		
