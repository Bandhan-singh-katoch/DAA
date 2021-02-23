//Write a program in C for Knapsack problem in which a thief is only greedy about profit but not weight.
# include<stdio.h>
void knapsack(int n, float weight[], float profit[], float capacity)
 { 
   float x[20], tw = 0;
   int i, j, u;
   u = capacity;
   for (i = 0; i < n; i++)
   {
      x[i] = 0.0;
    }
    
    for (i = 0; i < n; i++)
    { 
	   if (profit[i] > u)
       {
	   break;
       }
      else 
	  {
      x[i] = 1.0;
      tw = tw + weight[i];
	  u = u - profit[i];
	  }
    }
    if (i < n)
    x[i] = u / profit[i];
    tw = tw + (x[i] * weight[i]); 
     printf("\nThe result vector is:- ");

    for (i = 0; i < n; i++)
    {
	printf("%f\t", x[i]); 
    }
	
	printf("\nMaximum weight is:- %f", tw);
    
	}


 int main() 
 {
  float weight[20], profit[20], capacity;  // capacity = profit capacity
  int num, i, j;
  float ratio[20], temp;

  printf("\nEnter the no. of objects:- "); 
  scanf("%d", &num);
 
  printf("\nEnter the wts and profits of each object:- ");
  for (i = 0; i < num; i++)
  {
    scanf("%f %f", &weight[i], &profit[i]);
  }
 
  printf("\nEnter the profit capacity of knapsack:- "); 
  scanf("%f", &capacity);
    for (i = 0; i < num; i++)
	 { 
	 ratio[i] = profit[i] / weight[i];
	 }
	 
    for (i = 0; i < num; i++)
	 {
      for (j = i + 1; j < num; j++)
	  {
	    if (ratio[i] < ratio[j]) 
	    {
          temp = ratio[j];
	      ratio[j] = ratio[i]; 
	      ratio[i] = temp;
	     
		  temp = weight[j]; 
          weight[j] = weight[i];
		  weight[i] = temp; 
		 
		  temp = profit[j];
		  profit[j] = profit[i];
		  profit[i] = temp;
		   }
		   }
		   }
		   
       knapsack(num, weight, profit, capacity);
       return(0);
 }
