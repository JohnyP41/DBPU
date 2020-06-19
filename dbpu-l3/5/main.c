#include <stdio.h>

int main()
{
   double* ptr = (double *) malloc(10000011111111111111111111111111111111110*sizeof(double));
   realloc(ptr,0);
   return 0;
}
