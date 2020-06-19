#include <stdio.h>

int main()
{
   char *str;
   str = (char *) malloc(15);
   strcpy(str, "XD");
   free(str);
   free(str);//dwukrotne zwolnianie tego samego bloku.
   double* ptr = (double *) malloc(1000000*sizeof(double));//wyciek pamięci
}

/*Wersja poprawna

#include <stdio.h>

int main()
{
   char *str;
   str = (char *) malloc(15);
   strcpy(str, "XD");
   free(str);
}
*/
