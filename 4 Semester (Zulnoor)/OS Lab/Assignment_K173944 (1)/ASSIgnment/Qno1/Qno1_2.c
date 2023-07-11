#include<stdio.h>

int compare_int (const int *a, const int *b)
{
  return (int) (*a - *b);
}



int main()
{
	float waitTime[5]={0};		//initially waiting time is taken zero
	int burstTime[5]={2,1,8,4,5};

	float completion_time[5]={0};
	float TAT[5]={0};
	
	qsort(burstTime,5,sizeof(int),compare_int);
	int i;
	float temp=0,temp1;
	for(i=0;i<5;i++)
	{
		temp1=temp+burstTime[i];
		waitTime[i]=temp;
		completion_time[i]=temp1;
		temp=temp1;
		TAT[i]=completion_time[i];
	}
	
	printf("Process#    Burst time      wait time      compl: time\t\tTAT\n");
	
	temp1=0;    // for Waiting time
	temp=0;		// for Turn arround time;
	for(i=0;i<5;i++)	
	{
		printf("  %d\t\t %d\t\t %.0f\t\t %.0f\t\t %.0f\n",i,burstTime[i],waitTime[i],completion_time[i],TAT[i]);
		temp+=TAT[i];
		temp1+=waitTime[i];
		
	}
	temp1=temp1/5;
	temp=temp/5;
	printf("The AVG Waiting time is %f\n",temp1);
	printf("The AVG T.A.T time is %f\n",temp);	
	return 0;
}
	
	

