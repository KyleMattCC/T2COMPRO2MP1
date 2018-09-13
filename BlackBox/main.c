#include "revised chua_mp1.c"



int main()
{


  struct listTag *universe; // provide the data type of universe
                   // the universe will contain the words from enable2k.txt 
  

  // declare your other own local variables here



/*-- START BLACK BOX TEST HERE --*/

  /* initialize the universe of words */ 
  Initialize(&universe);



#if 0

  /* Test I: for Exact Match */
  Search(universe, "xylophone");    
  Search(universe, "XyLoPhoNE");    

  /* Test II: for NOMATCH */
  Search(universe, "compro2");      

#endif


#if 0

  /* Test III: for ? wildcard */
  Search(universe, "?ak");          
  Search(universe, "s?t");          
  Search(universe, "yi?");          
  Search(universe,"?g?s");          

#endif


#if 0

  /* Test for IV: * wildcard */
  Search(universe, "*ev");         
  Search(universe, "g*of");        
  Search(universe, "tui*");       
  Search(universe, "a*d*x");       
  Search(universe, "*ibur*");      

#endif


  /* Time stress test */
  Search(universe, "*");           
             

/*--- END BLACK BOX TEST HERE ---*/


  return 0;


}











