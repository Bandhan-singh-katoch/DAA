#include<stdio.h>

void knapsack(int n, float weight[], float profit[], float capacity)
{
	float u,x[20],tp = 0;
	int i,j;
	u = capacity;
	for(i=0;i<n;i++)
	{
	 x[i] = 0.0;
    }
    
    for(i=0;i<n;i++)
    {
    	if(weight[i]>u)
		{
		  break;
		}
		else
		{
			x[i] = 1.0;
			tp = tp + profit[i];
			u = u - weight[i];
		}
	}
	
	if(i<n)
	{
		x[i] = u/weight[i];
		tp = tp + (x[i]*profit[i]);
	}
	
	printf("\nThe result vector is:- ");
    for (i = 0; i < n; i++)
    printf("%f\t", x[i]); 
    printf("\nMaximum profit is:- %f", tp);


}
int main()
{
	int num,i,j;
	float wt[20],pr[20],cap,rat[20],temp;
	printf("Enter the no. of objects = ");
	scanf("%d",&num);
	printf("\nEnter the weights and profits = ");
	for(i=0;i<num;i++)
	{
		scanf("%f%f",&wt[i],&pr[i]);
	}
	
	printf("\nEnter the capacity of knapsack = ");
	scanf("%f",&cap);
	
	for(i=0;i<num;i++)
	{
		rat[i] = pr[i]/rat[i];
	}
	
	for(i=0;i<num;i++)
	{
		for(j=i+1;j<num;j++)
		{
			if(rat[i]<rat[j])
			{
				temp = pr[i];
				pr[i] = pr[j];
				pr[j] = temp;
				 
				 temp = rat[i];
				rat[i] = rat[j];
				rat[j] = temp;
				
				temp = wt[i];
				wt[i] = wt[j];
				wt[j] = temp;
			}
		}
	}
	knapsack(num, wt, pr, cap);
	return 0;
}
