#include <omp.h>
#include <stdio.h>

int main() 
{
  int r, i, j, k = 0;

	
  printf("Enter Size of Pyramid \n \n");
  scanf("%d",&r);

	
  printf("Star Pattern \n \n");
  
	#pragma omp parallel for num_threads(4)  
  for ( i = r ; i >= 1; i-- ) 
    {
      for ( j = 0 ; j <= r-i; j++ ) 
      {
      	printf(" ");    	
      }
      k = 0;
      while (k != (2 * i - 1))
      {
	printf("*"); 
	k++;
      }
      printf("\n");
    }
  return 0;
}
